typedef struct _FS_FILTER_CALLBACK_DATA {
  ULONG                 SizeOfFsFilterCallbackData;
  UCHAR                 Operation;
  UCHAR                 Reserved;
  struct _DEVICE_OBJECT *DeviceObject;
  struct _FILE_OBJECT   *FileObject;
  FS_FILTER_PARAMETERS  Parameters;
} FS_FILTER_CALLBACK_DATA, *PFS_FILTER_CALLBACK_DATA;