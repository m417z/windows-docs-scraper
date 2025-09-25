typedef struct _MF_TRANSCODE_SINK_INFO {
  DWORD        dwVideoStreamID;
  IMFMediaType *pVideoMediaType;
  DWORD        dwAudioStreamID;
  IMFMediaType *pAudioMediaType;
} MF_TRANSCODE_SINK_INFO;