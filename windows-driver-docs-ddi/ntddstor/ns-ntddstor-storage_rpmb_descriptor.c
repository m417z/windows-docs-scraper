typedef struct _STORAGE_RPMB_DESCRIPTOR {
  ULONG                   Version;
  ULONG                   Size;
  ULONG                   SizeInBytes;
  ULONG                   MaxReliableWriteSizeInBytes;
  STORAGE_RPMB_FRAME_TYPE FrameFormat;
} STORAGE_RPMB_DESCRIPTOR, *PSTORAGE_RPMB_DESCRIPTOR;