typedef struct _IO_SECURITY_CONTEXT {
  PSECURITY_QUALITY_OF_SERVICE SecurityQos;
  PACCESS_STATE                AccessState;
  ACCESS_MASK                  DesiredAccess;
  ULONG                        FullCreateOptions;
} IO_SECURITY_CONTEXT, *PIO_SECURITY_CONTEXT;