typedef struct _CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT {
  CLIENT_CONTROLLER_QUERY_SET_REQUEST_TYPE RequestType;
  USHORT                                   Size;
  ULONG                                    Flags;
  union {
    struct {
      BANK_ID BankId;
    } BankPowerInformation;
    struct {
      WDFCMRESLIST ResourcesTranslated;
      WDFCMRESLIST ResourcesRaw;
      USHORT       TotalBanks;
    } BankInterruptBinding;
    struct {
      PVOID  InputBuffer;
      SIZE_T InputBufferSize;
      SIZE_T OutputBufferSize;
      USHORT TotalBanks;
    } ControllerFunctionBankMapping;
  };
} CLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT, *PCLIENT_CONTROLLER_QUERY_SET_INFORMATION_INPUT;