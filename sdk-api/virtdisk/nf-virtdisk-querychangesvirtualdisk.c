DWORD QueryChangesVirtualDisk(
  [in]      HANDLE                            VirtualDiskHandle,
  [in]      PCWSTR                            ChangeTrackingId,
  [in]      ULONG64                           ByteOffset,
  [in]      ULONG64                           ByteLength,
  [in]      QUERY_CHANGES_VIRTUAL_DISK_FLAG   Flags,
  [out]     PQUERY_CHANGES_VIRTUAL_DISK_RANGE Ranges,
  [in, out] PULONG                            RangeCount,
  [out]     PULONG64                          ProcessedLength
);