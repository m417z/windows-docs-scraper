ISDSC_STATUS ISDSC_API SendScsiReadCapacity(
  [in]      PISCSI_UNIQUE_SESSION_ID UniqueSessionId,
  [in]      ULONGLONG                Lun,
  [out]     PUCHAR                   ScsiStatus,
  [in, out] PULONG                   ResponseSize,
  [out]     PUCHAR                   ResponseBuffer,
  [in, out] PULONG                   SenseSize,
  [out]     PUCHAR                   SenseBuffer
);