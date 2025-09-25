typedef struct _SFFDISK_DEVICE_PASSWORD_DATA {
  USHORT        Size;
  USHORT        Reserved;
  SFFDISK_DPCMD Command;
  ULONG_PTR     Information;
  UCHAR         PasswordLength;
  UCHAR         NewPasswordLength;
  UCHAR         Data[0];
} SFFDISK_DEVICE_PASSWORD_DATA, *PSFFDISK_DEVICE_PASSWORD_DATA;