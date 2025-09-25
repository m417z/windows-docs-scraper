NTSTATUS GetReadPacket(
  [out] ULONG   *PacketNumber,
  [out] DWORD   *Flags,
  [out] ULONG64 *PerformanceCounterValue,
  [out] BOOL    *MoreData
);