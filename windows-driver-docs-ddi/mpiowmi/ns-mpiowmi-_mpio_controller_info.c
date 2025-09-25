typedef struct _MPIO_CONTROLLER_INFO {
  ULONG IdentifierType;
  ULONG IdentifierLength;
  UCHAR Identifier[32];
  ULONG ControllerState;
  ULONG Pad;
  WCHAR AssociatedDsm[63 + 1];
} MPIO_CONTROLLER_INFO, *PMPIO_CONTROLLER_INFO;