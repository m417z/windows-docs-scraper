typedef struct IORING_BUFFER_REF {
  void            IORING_BUFFER_REF(
    void *address
  );
  void            IORING_BUFFER_REF(
    IORING_REGISTERED_BUFFER registeredBuffer
  );
  void            IORING_BUFFER_REF(
    UINT32 index,
    UINT32 offset
  );
  IORING_REF_KIND Kind;
  union {
    void                     *Address;
    IORING_REGISTERED_BUFFER IndexAndOffset;
  } BufferUnion;
  BufferUnion     Buffer;
} IORING_BUFFER_REF;