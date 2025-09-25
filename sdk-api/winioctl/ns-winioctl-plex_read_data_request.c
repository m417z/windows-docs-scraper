typedef struct _PLEX_READ_DATA_REQUEST {
  LARGE_INTEGER ByteOffset;
  DWORD         ByteLength;
  DWORD         PlexNumber;
} PLEX_READ_DATA_REQUEST, *PPLEX_READ_DATA_REQUEST;