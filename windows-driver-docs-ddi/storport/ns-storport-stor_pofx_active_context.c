typedef struct _STOR_POFX_ACTIVE_CONTEXT {
  STOR_POWER_CONTROL_HEADER Header;
  ULONG                     ComponentIndex;
  BOOLEAN                   Active;
} STOR_POFX_ACTIVE_CONTEXT, *PSTOR_POFX_ACTIVE_CONTEXT;