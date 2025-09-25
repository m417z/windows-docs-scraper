typedef struct IORING_HANDLE_REF {
  void            IORING_HANDLE_REF(
    HANDLE h
  );
  void            IORING_HANDLE_REF(
    UINT32 index
  );
  IORING_REF_KIND Kind;
  union {
    HANDLE Handle;
    UINT32 Index;
  } HandleUnion;
  HandleUnion     Handle;
} IORING_HANDLE_REF;