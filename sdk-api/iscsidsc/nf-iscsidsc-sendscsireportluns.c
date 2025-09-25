ISDSC_STATUS ISDSC_API SendScsiReportLuns(
  [in]      PISCSI_UNIQUE_SESSION_ID UniqueSessionId,
  [out]     PUCHAR                   ScsiStatus,
  [in, out] PULONG                   ResponseSize,
  [out]     PUCHAR                   ResponseBuffer,
  [in, out] PULONG                   SenseSize,
  [out]     PUCHAR                   SenseBuffer
);