HRESULT ErtIoctl(
  PCSTR          Message,
  EXT_TDOP       Op,
  ULONG          Flags,
  PCSTR          InStr,
  ULONG64        In64,
  ExtRemoteTyped *Ret,
  PSTR           StrBuffer,
  ULONG          StrBufferChars,
  PULONG         Out32
);