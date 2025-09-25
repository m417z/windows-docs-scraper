typedef struct _BLUETOOTH_RADIO_INFO {
  DWORD             dwSize;
  BLUETOOTH_ADDRESS address;
  WCHAR             szName[BLUETOOTH_MAX_NAME_SIZE];
  ULONG             ulClassofDevice;
  USHORT            lmpSubversion;
  USHORT            manufacturer;
} BLUETOOTH_RADIO_INFO, *PBLUETOOTH_RADIO_INFO;