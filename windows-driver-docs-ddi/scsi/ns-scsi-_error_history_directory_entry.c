typedef struct _ERROR_HISTORY_DIRECTORY_ENTRY {
  UCHAR SupportedBufferId;
  UCHAR BufferFormat;
  UCHAR BufferSource : 4;
  UCHAR Reserved0 : 4;
  UCHAR Reserved1;
  UCHAR MaxAvailableLength[4];
} ERROR_HISTORY_DIRECTORY_ENTRY, *PERROR_HISTORY_DIRECTORY_ENTRY;