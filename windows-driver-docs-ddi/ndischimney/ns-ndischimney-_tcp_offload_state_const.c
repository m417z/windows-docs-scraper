typedef struct _TCP_OFFLOAD_STATE_CONST {
  OFFLOAD_STATE_HEADER Header;
  USHORT               Flags;
  USHORT               RemotePort;
  USHORT               LocalPort;
  UCHAR                SndWindScale : 4;
  UCHAR                RcvWindScale : 4;
  USHORT               RemoteMss;
  ULONG                HashValue;
} TCP_OFFLOAD_STATE_CONST, *PTCP_OFFLOAD_STATE_CONST;