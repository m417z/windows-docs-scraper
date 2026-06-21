typedef enum _HEAP_INFORMATION_CLASS {
  HeapCompatibilityInformation = 0,
  HeapEnableTerminationOnCorruption = 1,
  HeapOptimizeResources = 3,
  HeapTag,
  HeapMemoryUsageInformation
} HEAP_INFORMATION_CLASS;