typedef struct _IO_STOP_ON_SYMLINK_FILTER_ECP_v0 {
  struct {
    ULONG ReparseCount;
    ULONG RemainingPathLength;
  } Out;
} IO_STOP_ON_SYMLINK_FILTER_ECP_v0, *PIO_STOP_ON_SYMLINK_FILTER_ECP_v0;