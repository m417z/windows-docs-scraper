typedef struct _SUB_Q_CURRENT_POSITION {
  SUB_Q_HEADER Header;
  UCHAR        FormatCode;
  UCHAR        Control : 4;
  UCHAR        ADR : 4;
  UCHAR        TrackNumber;
  UCHAR        IndexNumber;
  UCHAR        AbsoluteAddress[4];
  UCHAR        TrackRelativeAddress[4];
} SUB_Q_CURRENT_POSITION, *PSUB_Q_CURRENT_POSITION;