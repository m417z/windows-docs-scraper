typedef struct _HDAUDIO_CODEC_COMMAND {
  union {
    struct {
      ULONG Data : 8;
      ULONG VerbId : 12;
      ULONG Node : 8;
      ULONG CodecAddress : 4;
    } Verb8;
    struct {
      ULONG Data : 16;
      ULONG VerbId : 4;
      ULONG Node : 8;
      ULONG CodecAddress : 4;
    } Verb16;
    ULONG Command;
  };
} HDAUDIO_CODEC_COMMAND, *PHDAUDIO_CODEC_COMMAND;