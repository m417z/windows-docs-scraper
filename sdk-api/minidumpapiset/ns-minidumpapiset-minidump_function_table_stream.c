typedef struct _MINIDUMP_FUNCTION_TABLE_STREAM {
  ULONG32 SizeOfHeader;
  ULONG32 SizeOfDescriptor;
  ULONG32 SizeOfNativeDescriptor;
  ULONG32 SizeOfFunctionEntry;
  ULONG32 NumberOfDescriptors;
  ULONG32 SizeOfAlignPad;
} MINIDUMP_FUNCTION_TABLE_STREAM, *PMINIDUMP_FUNCTION_TABLE_STREAM;