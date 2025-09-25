typedef struct _BLUETOOTH_AUTHENTICATE_RESPONSE {
  BLUETOOTH_ADDRESS               bthAddressRemote;
  BLUETOOTH_AUTHENTICATION_METHOD authMethod;
  union {
    BLUETOOTH_PIN_INFO                pinInfo;
    BLUETOOTH_OOB_DATA_INFO           oobInfo;
    BLUETOOTH_NUMERIC_COMPARISON_INFO numericCompInfo;
    BLUETOOTH_PASSKEY_INFO            passkeyInfo;
  };
  UCHAR                           negativeResponse;
} BLUETOOTH_AUTHENTICATE_RESPONSE, *PBLUETOOTH_AUTHENTICATE_RESPONSE;