typedef union _INLINE_FRAME_CONTEXT {
  DWORD  ContextValue;
  struct {
    BYTE FrameId;
    BYTE FrameType;
    WORD FrameSignature;
  };
} INLINE_FRAME_CONTEXT;