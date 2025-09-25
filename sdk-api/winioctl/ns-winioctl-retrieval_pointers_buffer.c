typedef struct RETRIEVAL_POINTERS_BUFFER {
  DWORD                    ExtentCount;
  LARGE_INTEGER            StartingVcn;
  struct {
    LARGE_INTEGER NextVcn;
    LARGE_INTEGER Lcn;
  };
  __unnamed_struct_0430_64 Extents[1];
} RETRIEVAL_POINTERS_BUFFER, *PRETRIEVAL_POINTERS_BUFFER;