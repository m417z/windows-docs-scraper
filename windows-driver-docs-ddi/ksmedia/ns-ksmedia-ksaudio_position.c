typedef struct {
#if ...
  ULONGLONG PlayOffset;
#if ...
  ULONGLONG WriteOffset;
#else
  DWORDLONG PlayOffset;
#endif
#else
  DWORDLONG WriteOffset;
#endif
} KSAUDIO_POSITION, *PKSAUDIO_POSITION;