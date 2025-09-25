typedef struct _AVCSTRM_BUFFER_STRUCT {
  BOOL             ClockProvider;
  HANDLE           ClockHandle;
  PKSSTREAM_HEADER StreamHeader;
  PVOID            FrameBuffer;
  PVOID            Context;
} AVCSTRM_BUFFER_STRUCT, *PAVCSTRM_BUFFER_STRUCT;