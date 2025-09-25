typedef struct _MFBYTESTREAM_BUFFERING_PARAMS {
  QWORD                cbTotalFileSize;
  QWORD                cbPlayableDataSize;
  MF_LEAKY_BUCKET_PAIR *prgBuckets;
  DWORD                cBuckets;
  QWORD                qwNetBufferingTime;
  QWORD                qwExtraBufferingTimeDuringSeek;
  QWORD                qwPlayDuration;
  float                dRate;
} MFBYTESTREAM_BUFFERING_PARAMS;