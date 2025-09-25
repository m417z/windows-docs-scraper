typedef struct _TRACK_DATA {
  UCHAR Reserved;
  UCHAR Control : 4;
  UCHAR Adr : 4;
  UCHAR TrackNumber;
  UCHAR Reserved1;
  UCHAR Address[4];
} TRACK_DATA, *PTRACK_DATA;