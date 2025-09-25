typedef struct _NDK_LOGICAL_ADDRESS_MAPPING {
  PVOID               AdapterContext;
  ULONG               AdapterPageCount;
  NDK_LOGICAL_ADDRESS AdapterPageArray[1];
} NDK_LOGICAL_ADDRESS_MAPPING;