typedef struct tagStorageLayout {
  DWORD         LayoutType;
  OLECHAR       *pwcsElementName;
  LARGE_INTEGER cOffset;
  LARGE_INTEGER cBytes;
} StorageLayout;