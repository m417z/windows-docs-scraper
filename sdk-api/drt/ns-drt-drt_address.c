typedef struct _DRT_ADDRESS {
  SOCKADDR_STORAGE socketAddress;
  ULONG            flags;
  LONG             nearness;
  ULONG            latency;
} DRT_ADDRESS, *PDRT_ADDRESS;