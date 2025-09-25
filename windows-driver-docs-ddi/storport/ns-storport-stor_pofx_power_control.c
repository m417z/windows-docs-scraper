typedef struct _STOR_POFX_POWER_CONTROL {
  STOR_POWER_CONTROL_HEADER Header;
  LPCGUID                   PowerControlCode;
  SIZE_T                    InBufferSize;
  SIZE_T                    OutBufferSize;
  PVOID                     InBuffer;
  PVOID                     OutBuffer;
  PSIZE_T                   BytesReturned;
} STOR_POFX_POWER_CONTROL, *PSTOR_POFX_POWER_CONTROL;