typedef struct _STORAGE_RPMB_DESCRIPTOR {
  DWORD                   Version;
  DWORD                   Size;
  DWORD                   SizeInBytes;
  DWORD                   MaxReliableWriteSizeInBytes;
  STORAGE_RPMB_FRAME_TYPE FrameFormat;
} STORAGE_RPMB_DESCRIPTOR, *PSTORAGE_RPMB_DESCRIPTOR;