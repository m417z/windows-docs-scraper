typedef struct _IO_DRIVER_CREATE_CONTEXT {
  CSHORT               Size;
  struct _ECP_LIST     *ExtraCreateParameter;
  PVOID                DeviceObjectHint;
  PTXN_PARAMETER_BLOCK TxnParameters;
  PESILO               SiloContext;
} IO_DRIVER_CREATE_CONTEXT, *PIO_DRIVER_CREATE_CONTEXT;