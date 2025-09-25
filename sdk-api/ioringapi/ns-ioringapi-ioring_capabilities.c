typedef struct IORING_CAPABILITIES {
  IORING_VERSION       MaxVersion;
  UINT32               MaxSubmissionQueueSize;
  UINT32               MaxCompletionQueueSize;
  IORING_FEATURE_FLAGS FeatureFlags;
} IORING_CAPABILITIES;