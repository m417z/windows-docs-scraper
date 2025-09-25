typedef struct _DISK_GEOMETRY {
  LARGE_INTEGER Cylinders;
  MEDIA_TYPE    MediaType;
  ULONG         TracksPerCylinder;
  ULONG         SectorsPerTrack;
  ULONG         BytesPerSector;
} DISK_GEOMETRY, *PDISK_GEOMETRY;