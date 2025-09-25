typedef struct _IPX_PATTERN {
  struct {
         ULONG  NetworkAddress;
         UCHAR  NodeAddress[6];
         USHORT Socket;
  } Src;
       __unnamed_struct_002d_4 Dest;
} IPX_PATTERN, *PIPX_PATTERN;