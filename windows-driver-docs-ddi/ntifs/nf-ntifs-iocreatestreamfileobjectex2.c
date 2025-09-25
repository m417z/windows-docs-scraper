NTSTATUS IoCreateStreamFileObjectEx2(
  [in]            PIO_CREATE_STREAM_FILE_OPTIONS CreateOptions,
  [in, optional]  PFILE_OBJECT                   FileObject,
  [in, optional]  PDEVICE_OBJECT                 DeviceObject,
  [out]           PFILE_OBJECT                   *StreamFileObject,
  [out, optional] PHANDLE                        FileHandle
);