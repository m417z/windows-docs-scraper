NTSTATUS GetMapping(
  [in]  PVOID             Tag,
  [out] PPHYSICAL_ADDRESS PhysicalAddress,
  [out] PVOID             *VirtualAddress,
  [out] PULONG            ByteCount,
  [out] PULONG            Flags
);