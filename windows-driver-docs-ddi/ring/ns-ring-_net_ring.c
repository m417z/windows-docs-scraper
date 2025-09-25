typedef struct _NET_RING {
  UINT16        OSReserved1;
  UINT16        ElementStride;
  UINT32        NumberOfElements;
  UINT32        ElementIndexMask;
  UINT32        EndIndex;
  union {
    UINT32 OSReserved0;
    void   *OSReserved2[4];
  } DUMMYUNIONNAME;
  UINT32        BeginIndex;
  UINT32        NextIndex;
  void          *Scratch;
  unsigned char Buffer[ANYSIZE_ARRAY];
} NET_RING;