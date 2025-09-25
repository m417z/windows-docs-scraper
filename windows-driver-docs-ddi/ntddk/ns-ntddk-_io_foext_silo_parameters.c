typedef struct _IO_FOEXT_SILO_PARAMETERS {
  ULONG  Length;
  union {
    struct {
      ULONG HasHardReference : 1;
      ULONG SpareFlags : 31;
    };
    ULONG Flags;
  };
  PESILO SiloContext;
} IO_FOEXT_SILO_PARAMETERS, *PIO_FOEXT_SILO_PARAMETERS;