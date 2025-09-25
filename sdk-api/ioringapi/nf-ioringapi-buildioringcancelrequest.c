HRESULT BuildIoRingCancelRequest(
  HIORING           ioRing,
  IORING_HANDLE_REF file,
  UINT_PTR          opToCancel,
  UINT_PTR          userData
);