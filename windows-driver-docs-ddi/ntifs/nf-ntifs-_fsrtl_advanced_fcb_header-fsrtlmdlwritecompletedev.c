BOOLEAN FsRtlMdlWriteCompleteDev(
  [in]             PFILE_OBJECT   FileObject,
  [in]             PLARGE_INTEGER FileOffset,
  [in]             PMDL           MdlChain,
  [ in, optional ] PDEVICE_OBJECT DeviceObject
);