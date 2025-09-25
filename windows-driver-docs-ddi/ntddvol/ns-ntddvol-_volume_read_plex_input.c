typedef struct _VOLUME_READ_PLEX_INPUT {
  LARGE_INTEGER ByteOffset;
  ULONG         Length;
  ULONG         PlexNumber;
} VOLUME_READ_PLEX_INPUT, *PVOLUME_READ_PLEX_INPUT;