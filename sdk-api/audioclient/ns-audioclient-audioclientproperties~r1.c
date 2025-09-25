typedef struct AudioClientProperties {
  UINT32                cbSize;
  BOOL                  bIsOffload;
  AUDIO_STREAM_CATEGORY eCategory;
  AUDCLNT_STREAMOPTIONS Options;
} AudioClientProperties;