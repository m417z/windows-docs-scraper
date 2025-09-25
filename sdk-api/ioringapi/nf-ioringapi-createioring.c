HRESULT CreateIoRing(
  IORING_VERSION      ioringVersion,
  IORING_CREATE_FLAGS flags,
  UINT32              submissionQueueSize,
  UINT32              completionQueueSize,
  HIORING             *h
);