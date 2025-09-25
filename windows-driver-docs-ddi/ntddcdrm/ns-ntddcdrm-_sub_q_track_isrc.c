typedef struct _SUB_Q_TRACK_ISRC {
  SUB_Q_HEADER Header;
  UCHAR        FormatCode;
  UCHAR        Reserved0;
  UCHAR        Track;
  UCHAR        Reserved1;
  UCHAR        Reserved2 : 7;
  UCHAR        Tcval : 1;
  UCHAR        TrackIsrc[15];
} SUB_Q_TRACK_ISRC, *PSUB_Q_TRACK_ISRC;