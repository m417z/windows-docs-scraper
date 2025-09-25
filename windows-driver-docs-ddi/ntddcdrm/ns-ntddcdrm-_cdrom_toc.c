typedef struct _CDROM_TOC {
  UCHAR      Length[2];
  UCHAR      FirstTrack;
  UCHAR      LastTrack;
  TRACK_DATA TrackData[MAXIMUM_NUMBER_TRACKS];
} CDROM_TOC, *PCDROM_TOC;