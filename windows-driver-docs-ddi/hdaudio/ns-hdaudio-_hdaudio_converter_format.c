typedef struct _HDAUDIO_CONVERTER_FORMAT {
  union {
    struct {
      USHORT NumberOfChannels : 4;
      USHORT BitsPerSample : 3;
      USHORT SampleRate : 7;
      USHORT StreamType : 1;
    };
    USHORT ConverterFormat;
  };
} HDAUDIO_CONVERTER_FORMAT, *PHDAUDIO_CONVERTER_FORMAT;