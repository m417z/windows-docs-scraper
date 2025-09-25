typedef struct _STOR_POFX_FSTATE_CONTEXT {
  STOR_POWER_CONTROL_HEADER Header;
  ULONG                     ComponentIndex;
  ULONG                     FState;
} STOR_POFX_FSTATE_CONTEXT, *PSTOR_POFX_FSTATE_CONTEXT;