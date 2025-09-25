typedef struct _UCSI_GET_CONNECTOR_CAPABILITY_IN {
  union {
    UINT8 AsUInt8;
    struct {
      UINT8 DfpOnly : 1;
      UINT8 UfpOnly : 1;
      UINT8 Drp : 1;
      UINT8 AudioAccessoryMode : 1;
      UINT8 DebugAccessoryMode : 1;
      UINT8 Usb2 : 1;
      UINT8 Usb3 : 1;
      UINT8 AlternateMode : 1;
    };
  } OperationMode;
  UINT8 Provider : 1;
  UINT8 Consumer : 1;
  UINT8 SwapToDfp : 1;
  UINT8 SwapToUfp : 1;
  UINT8 SwapToSrc : 1;
  UINT8 SwapToSnk : 1;
} UCSI_GET_CONNECTOR_CAPABILITY_IN, *PUCSI_GET_CONNECTOR_CAPABILITY_IN;