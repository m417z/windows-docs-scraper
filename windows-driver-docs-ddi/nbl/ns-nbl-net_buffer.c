typedef struct _NET_BUFFER {
  union {
    struct {
      NET_BUFFER *Next;
      MDL        *CurrentMdl;
      ULONG      CurrentMdlOffset;
      union {
        ULONG  DataLength;
        SIZE_T stDataLength;
      };
      MDL        *MdlChain;
      ULONG      DataOffset;
    };
    SLIST_HEADER      Link;
    NET_BUFFER_HEADER NetBufferHeader;
  };
  USHORT           ChecksumBias;
  USHORT           Reserved;
  NDIS_HANDLE      NdisPoolHandle;
  PVOID            NdisReserved[2];
  PVOID            ProtocolReserved[6];
  PVOID            MiniportReserved[4];
  PHYSICAL_ADDRESS DataPhysicalAddress;
  union {
    NET_BUFFER_SHARED_MEMORY *SharedMemoryInfo;
    SCATTER_GATHER_LIST      *ScatterGatherList;
  };
} NET_BUFFER, *PNET_BUFFER;