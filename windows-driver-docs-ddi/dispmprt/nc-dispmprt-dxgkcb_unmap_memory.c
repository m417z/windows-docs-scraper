DXGKCB_UNMAP_MEMORY DxgkcbUnmapMemory;

NTSTATUS DxgkcbUnmapMemory(
  [in] HANDLE DeviceHandle,
  [in] PVOID VirtualAddress
)
{...}