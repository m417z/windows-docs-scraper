HRESULT BuildIoRingReadFile(
  HIORING           ioRing,
  IORING_HANDLE_REF fileRef,
  IORING_BUFFER_REF dataRef,
  UINT32            numberOfBytesToRead,
  UINT64            fileOffset,
  UINT_PTR          userData,
  IORING_SQE_FLAGS  sqeFlags
);