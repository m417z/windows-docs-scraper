typedef struct IORING_INFO {
  IORING_VERSION      IoRingVersion;
  IORING_CREATE_FLAGS Flags;
  UINT32              SubmissionQueueSize;
  UINT32              CompletionQueueSize;
} IORING_INFO;