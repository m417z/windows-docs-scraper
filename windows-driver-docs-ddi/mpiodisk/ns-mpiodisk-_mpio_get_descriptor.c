typedef struct _MPIO_GET_DESCRIPTOR {
  ULONG           NumberPdos;
  WCHAR           DeviceName[63 + 1];
  PDO_INFORMATION PdoInformation[1];
} MPIO_GET_DESCRIPTOR, *PMPIO_GET_DESCRIPTOR;