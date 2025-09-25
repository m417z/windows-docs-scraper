typedef struct _TARGET_DEVICE_CUSTOM_NOTIFICATION {
  USHORT       Version;
  USHORT       Size;
  GUID         Event;
  PFILE_OBJECT FileObject;
  LONG         NameBufferOffset;
  UCHAR        CustomDataBuffer[1];
} TARGET_DEVICE_CUSTOM_NOTIFICATION, *PTARGET_DEVICE_CUSTOM_NOTIFICATION;