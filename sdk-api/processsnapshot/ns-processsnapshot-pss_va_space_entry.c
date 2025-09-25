typedef struct {
  void          *BaseAddress;
  void          *AllocationBase;
  DWORD         AllocationProtect;
  ULONG_PTR     RegionSize;
  DWORD         State;
  DWORD         Protect;
  DWORD         Type;
  DWORD         TimeDateStamp;
  DWORD         SizeOfImage;
  void          *ImageBase;
  DWORD         CheckSum;
  WORD          MappedFileNameLength;
  wchar_t const *MappedFileName;
} PSS_VA_SPACE_ENTRY;