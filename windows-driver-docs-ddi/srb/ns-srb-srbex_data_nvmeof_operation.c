typedef struct _SRBEX_DATA_NVMEOF_OPERATION {
  SRBEXDATATYPE Type;
  ULONG         Length;
  USHORT        Version;
  USHORT        Reserved1;
  ULONG         Flags;
  ULONG         FunctionType;
} SRBEX_DATA_NVMEOF_OPERATION, *PSRBEX_DATA_NVMEOF_OPERATION;