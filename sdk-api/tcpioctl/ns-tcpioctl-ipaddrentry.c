typedef struct IPAddrEntry {
  ulong  iae_addr;
  ulong  iae_index;
  ulong  iae_mask;
  ulong  iae_bcastaddr;
  ulong  iae_reasmsize;
  ushort iae_context;
  ushort iae_pad;
} IPAddrEntry;