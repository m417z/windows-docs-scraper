typedef struct _WDF_MEMORY_DESCRIPTOR {
  WDF_MEMORY_DESCRIPTOR_TYPE Type;
  union {
    struct {
      PVOID Buffer;
      ULONG Length;
    } BufferType;
    struct {
      PMDL  Mdl;
      ULONG BufferLength;
    } MdlType;
    struct {
      WDFMEMORY         Memory;
      PWDFMEMORY_OFFSET Offsets;
    } HandleType;
  } u;
} WDF_MEMORY_DESCRIPTOR, *PWDF_MEMORY_DESCRIPTOR;