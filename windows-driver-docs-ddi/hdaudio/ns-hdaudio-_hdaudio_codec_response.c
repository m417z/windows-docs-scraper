typedef struct _HDAUDIO_CODEC_RESPONSE {
  union {
    struct {
      union {
        struct {
          ULONG Response : 21;
          ULONG SubTag : 5;
          ULONG Tag : 6;
        } Unsolicited;
        ULONG Response;
      };
      ULONG SDataIn : 4;
      ULONG IsUnsolicitedResponse : 1;
      ULONG HasFifoOverrun : 1;
      ULONG IsValid : 1;
    };
    ULONGLONG CompleteResponse;
  };
} HDAUDIO_CODEC_RESPONSE, *PHDAUDIO_CODEC_RESPONSE;