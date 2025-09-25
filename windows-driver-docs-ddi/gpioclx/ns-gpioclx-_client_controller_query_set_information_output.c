typedef struct _CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT {
  USHORT Version;
  USHORT Size;
  union {
    CLIENT_QUERY_BANK_POWER_INFORMATION_OUTPUT BankPowerInformation;
    struct {
      ULONG ResourceMapping[ANYSIZE_ARRAY];
    } BankInterruptBinding;
    struct {
      BOOLEAN Mapping[ANYSIZE_ARRAY];
    } ControllerFunctionBankMapping;
  };
} CLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT, *PCLIENT_CONTROLLER_QUERY_SET_INFORMATION_OUTPUT;