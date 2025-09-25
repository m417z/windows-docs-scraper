DWORD RawSCSIVirtualDisk(
  [in]  HANDLE                                  VirtualDiskHandle,
  [in]  const PRAW_SCSI_VIRTUAL_DISK_PARAMETERS Parameters,
  [in]  RAW_SCSI_VIRTUAL_DISK_FLAG              Flags,
  [out] PRAW_SCSI_VIRTUAL_DISK_RESPONSE         Response
);