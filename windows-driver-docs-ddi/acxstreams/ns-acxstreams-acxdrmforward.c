typedef struct _ACXDRMFORWARD {
  ULONG          Flags;
  PDEVICE_OBJECT DeviceObject;
  PFILE_OBJECT   FileObject;
  PVOID          Context;
} ACXDRMFORWARD, *PACXDRMFORWARD;