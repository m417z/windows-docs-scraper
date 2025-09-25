typedef struct _STOR_POFX_DEVICE {
  ULONG               Version;
  ULONG               Size;
  ULONG               ComponentCount;
  ULONG               Flags;
  STOR_POFX_COMPONENT Components[ANYSIZE_ARRAY];
} STOR_POFX_DEVICE, *PSTOR_POFX_DEVICE;