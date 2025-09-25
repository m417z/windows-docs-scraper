typedef struct FILE_ID_DESCRIPTOR {
  DWORD        dwSize;
  FILE_ID_TYPE Type;
  union {
    LARGE_INTEGER FileId;
    GUID          ObjectId;
    FILE_ID_128   ExtendedFileId;
  } DUMMYUNIONNAME;
} FILE_ID_DESCRIPTOR, *LPFILE_ID_DESCRIPTOR;