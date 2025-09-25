__kernel_entry NTSYSCALLAPI NTSTATUS NtManagePartition(
  [in]           HANDLE                      TargetHandle,
  [in, optional] HANDLE                      SourceHandle,
  [in]           PARTITION_INFORMATION_CLASS PartitionInformationClass,
  [in, out]      PVOID                       PartitionInformation,
  [in]           ULONG                       PartitionInformationLength
);