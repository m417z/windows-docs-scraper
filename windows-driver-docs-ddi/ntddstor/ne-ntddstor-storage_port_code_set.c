typedef enum _STORAGE_PORT_CODE_SET {
  StoragePortCodeSetReserved,
  StoragePortCodeSetStorport,
  StoragePortCodeSetSCSIport,
  StoragePortCodeSetSpaceport,
  StoragePortCodeSetATAport,
  StoragePortCodeSetUSBport,
  StoragePortCodeSetSBP2port,
  StoragePortCodeSetSDport
} STORAGE_PORT_CODE_SET, *PSTORAGE_PORT_CODE_SET;