typedef struct _DISK_GEOMETRY {
  LARGE_INTEGER Cylinders;
  MEDIA_TYPE    MediaType;
  DWORD         TracksPerCylinder;
  DWORD         SectorsPerTrack;
  DWORD         BytesPerSector;
} DISK_GEOMETRY, *PDISK_GEOMETRY;