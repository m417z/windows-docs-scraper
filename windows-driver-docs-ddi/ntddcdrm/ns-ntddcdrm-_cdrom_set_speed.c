typedef struct _CDROM_SET_SPEED {
  CDROM_SPEED_REQUEST RequestType;
  USHORT              ReadSpeed;
  USHORT              WriteSpeed;
  WRITE_ROTATION      RotationControl;
} CDROM_SET_SPEED, *PCDROM_SET_SPEED;