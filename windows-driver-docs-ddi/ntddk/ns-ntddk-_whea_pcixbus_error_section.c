typedef struct _WHEA_PCIXBUS_ERROR_SECTION {
  WHEA_PCIXBUS_ERROR_SECTION_VALIDBITS ValidBits;
  WHEA_ERROR_STATUS                    ErrorStatus;
  USHORT                               ErrorType;
  WHEA_PCIXBUS_ID                      BusId;
  ULONG                                Reserved;
  ULONGLONG                            BusAddress;
  ULONGLONG                            BusData;
  WHEA_PCIXBUS_COMMAND                 BusCommand;
  ULONGLONG                            RequesterId;
  ULONGLONG                            CompleterId;
  ULONGLONG                            TargetId;
} WHEA_PCIXBUS_ERROR_SECTION, *PWHEA_PCIXBUS_ERROR_SECTION;