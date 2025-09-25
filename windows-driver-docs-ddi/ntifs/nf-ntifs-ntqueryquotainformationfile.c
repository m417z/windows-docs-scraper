__kernel_entry NTSYSCALLAPI NTSTATUS NtQueryQuotaInformationFile(
  [in]           HANDLE           FileHandle,
  [out]          PIO_STATUS_BLOCK IoStatusBlock,
  [out]          PVOID            Buffer,
  [in]           ULONG            Length,
  [in]           BOOLEAN          ReturnSingleEntry,
  [in, optional] PVOID            SidList,
  [in]           ULONG            SidListLength,
  [in, optional] PSID             StartSid,
  [in]           BOOLEAN          RestartScan
);