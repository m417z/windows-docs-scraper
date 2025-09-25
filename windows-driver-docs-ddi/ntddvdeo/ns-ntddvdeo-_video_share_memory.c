typedef struct _VIDEO_SHARE_MEMORY {
  HANDLE ProcessHandle;
  ULONG  ViewOffset;
  ULONG  ViewSize;
  PVOID  RequestedVirtualAddress;
} VIDEO_SHARE_MEMORY, *PVIDEO_SHARE_MEMORY;