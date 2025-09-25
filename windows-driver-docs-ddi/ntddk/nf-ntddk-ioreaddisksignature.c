NTSTATUS IoReadDiskSignature(
  [in]  PDEVICE_OBJECT  DeviceObject,
  [in]  ULONG           BytesPerSector,
  [out] PDISK_SIGNATURE Signature
);