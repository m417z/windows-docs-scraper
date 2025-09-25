typedef struct _VDS_DRIVE_LETTER_NOTIFICATION {
  ULONG         ulEvent;
  WCHAR         wcLetter;
  VDS_OBJECT_ID volumeId;
} VDS_DRIVE_LETTER_NOTIFICATION;