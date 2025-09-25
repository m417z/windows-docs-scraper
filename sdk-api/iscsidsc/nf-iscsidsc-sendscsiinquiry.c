ISDSC_STATUS ISDSC_API SendScsiInquiry(
  [in]      PISCSI_UNIQUE_SESSION_ID UniqueSessionId,
  [in]      ULONGLONG                Lun,
  [in]      UCHAR                    EvpdCmddt,
  [in]      UCHAR                    PageCode,
  [out]     PUCHAR                   ScsiStatus,
  [in, out] PULONG                   ResponseSize,
  [out]     PUCHAR                   ResponseBuffer,
  [in, out] PULONG                   SenseSize,
  [out]     PUCHAR                   SenseBuffer
);