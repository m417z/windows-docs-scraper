typedef struct _VDS_DRIVE_LETTER_PROP {
  WCHAR         wcLetter;
  VDS_OBJECT_ID volumeId;
  ULONG         ulFlags;
  BOOL          bUsed;
} VDS_DRIVE_LETTER_PROP, *PVDS_DRIVE_LETTER_PROP;