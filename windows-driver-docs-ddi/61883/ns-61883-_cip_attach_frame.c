typedef struct _CIP_ATTACH_FRAME {
  HANDLE     hConnect;
  ULONG      FrameLength;
  ULONG      SourceLength;
  PCIP_FRAME Frame;
} CIP_ATTACH_FRAME, *PCIP_ATTACH_FRAME;