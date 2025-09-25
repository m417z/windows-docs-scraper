typedef struct _WSK_EXTENSION_CONTROL_IN {
  PNPIID     NpiId;
  PVOID      ClientContext;
  const VOID *ClientDispatch;
} WSK_EXTENSION_CONTROL_IN, *PWSK_EXTENSION_CONTROL_IN;