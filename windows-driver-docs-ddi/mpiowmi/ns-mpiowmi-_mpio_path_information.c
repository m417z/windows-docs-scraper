typedef struct _MPIO_PATH_INFORMATION {
  ULONG                    NumberPaths;
  ULONG                    Pad;
  MPIO_ADAPTER_INFORMATION PathList[1];
} MPIO_PATH_INFORMATION, *PMPIO_PATH_INFORMATION;