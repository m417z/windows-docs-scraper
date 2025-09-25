typedef struct _STORAGE_REINITIALIZE_MEDIA {
  ULONG  Version;
  ULONG  Size;
  ULONG  TimeoutInSeconds;
  struct {
    ULONG SanitizeMethod : 4;
    ULONG DisallowUnrestrictedSanitizeExit : 1;
    ULONG Reserved : 27;
  } SanitizeOption;
} STORAGE_REINITIALIZE_MEDIA, *PSTORAGE_REINITIALIZE_MEDIA;