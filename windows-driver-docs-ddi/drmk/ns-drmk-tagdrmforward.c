typedef struct tagDRMFORWARD {
  DWORD          Flags;
  PDEVICE_OBJECT DeviceObject;
  PFILE_OBJECT   FileObject;
  PVOID          Context;
} DRMFORWARD, *PDRMFORWARD;