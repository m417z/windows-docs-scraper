typedef struct _CDROM_SET_STREAMING {
  CDROM_SPEED_REQUEST RequestType;
  ULONG               ReadSize;
  ULONG               ReadTime;
  ULONG               WriteSize;
  ULONG               WriteTime;
  ULONG               StartLba;
  ULONG               EndLba;
  WRITE_ROTATION      RotationControl;
  BOOLEAN             RestoreDefaults;
  BOOLEAN             SetExact;
  BOOLEAN             RandomAccess;
  BOOLEAN             Persistent;
} CDROM_SET_STREAMING, *PCDROM_SET_STREAMING;