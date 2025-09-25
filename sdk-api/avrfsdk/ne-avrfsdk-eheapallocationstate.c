typedef enum eHeapAllocationState {
  HeapFullPageHeap = 0x40000000,
  HeapMetadata = 0x80000000,
  HeapStateMask = 0xFFFF0000
} ;