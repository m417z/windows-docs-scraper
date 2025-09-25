typedef struct _WIN32_STREAM_ID {
  DWORD         dwStreamId;
  DWORD         dwStreamAttributes;
  LARGE_INTEGER Size;
  DWORD         dwStreamNameSize;
  WCHAR         cStreamName[ANYSIZE_ARRAY];
} WIN32_STREAM_ID, *LPWIN32_STREAM_ID;