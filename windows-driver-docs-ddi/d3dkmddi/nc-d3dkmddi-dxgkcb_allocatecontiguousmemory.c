DXGKCB_ALLOCATECONTIGUOUSMEMORY DxgkcbAllocatecontiguousmemory;

NTSTATUS DxgkcbAllocatecontiguousmemory(
  [in]     IN_CONST_HANDLE hAdapter,
  [in/out] INOUT_PDXGKARGCB_ALLOCATECONTIGUOUSMEMORY pAllocateContiguousMemory
)
{...}