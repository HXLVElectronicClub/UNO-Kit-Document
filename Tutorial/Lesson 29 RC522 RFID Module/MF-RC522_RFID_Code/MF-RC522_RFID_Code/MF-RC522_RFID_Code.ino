
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN   9     // Configurable, see typical pin layout above
#define SS_PIN    10    // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

/* Set your new UID here! */
#define NEW_UID {0xDE, 0xAD, 0xBE, 0xEF}

MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);  // Initialize serial communications with the PC
  while (!Serial);     // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();         // Init SPI bus
  mfrc522.PCD_Init();  // Init MFRC522 card
  Serial.println(F("Warning: this example overwrites the UID of your UID changeable card, use with care!"));
  
  // Prepare key - all keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

// Setting the UID can be as simple as this:
//void loop() {
//  byte newUid[] = NEW_UID;
//  if ( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) ) {
//    Serial.println("Wrote new UID to card.");
//  }
//  delay(2000);
//}

// But of course this is a more proper approach
void loop() {
  
  // Look for new cards, and select one if present
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(1000);
    return;
  }
  
  // Now a card is selected. The UID and SAK is in mfrc522.uid.
  
  // Dump UID
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();

  // Dump PICC type
//  MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
//  Serial.print(F("PICC type: "));
//  Serial.print(mfrc522.PICC_GetTypeName(piccType));
//  Serial.print(F(" (SAK "));
//  Serial.print(mfrc522.uid.sak);
//  Serial.print(")\r\n");
//  if (  piccType != MFRC522::PICC_TYPE_MIFARE_MINI 
//    &&  piccType != MFRC522::PICC_TYPE_MIFARE_1K
//    &&  piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
//    Serial.println(F("This sample only works with MIFARE Classic cards."));
//    return;
//  }
  
  // Set new UID
  byte newUid[] = NEW_UID;
  if ( mfrc522.MIFARE_SetUid(newUid, (byte)4, true) ) {
    Serial.println(F("Wrote new UID to card."));
  }
  
  // Halt PICC and re-select it so DumpToSerial doesn't get confused
  mfrc522.PICC_HaltA();
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    return;
  }
  
  // Dump the new memory contents
  Serial.println(F("New UID and contents:"));
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  delay(3000);
}
