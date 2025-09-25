typedef struct _TAPE_GET_MEDIA_PARAMETERS {
  LARGE_INTEGER Capacity;
  LARGE_INTEGER Remaining;
  DWORD         BlockSize;
  DWORD         PartitionCount;
  BOOLEAN       WriteProtected;
} TAPE_GET_MEDIA_PARAMETERS, *PTAPE_GET_MEDIA_PARAMETERS;