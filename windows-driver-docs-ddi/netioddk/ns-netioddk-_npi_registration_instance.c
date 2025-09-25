typedef struct _NPI_REGISTRATION_INSTANCE {
  USHORT        Version;
  USHORT        Size;
  PNPIID        NpiId;
  PNPI_MODULEID ModuleId;
  ULONG         Number;
  const VOID    *NpiSpecificCharacteristics;
} NPI_REGISTRATION_INSTANCE;