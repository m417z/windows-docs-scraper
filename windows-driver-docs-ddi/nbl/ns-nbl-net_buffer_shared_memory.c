typedef struct _NET_BUFFER_SHARED_MEMORY {
  NET_BUFFER_SHARED_MEMORY *NextSharedMemorySegment;
  ULONG                    SharedMemoryFlags;
  NDIS_HANDLE              SharedMemoryHandle;
  ULONG                    SharedMemoryOffset;
  ULONG                    SharedMemoryLength;
} NET_BUFFER_SHARED_MEMORY, *PNET_BUFFER_SHARED_MEMORY;