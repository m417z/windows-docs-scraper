typedef enum tagCSC_SynchronizationConfig {
  CSC_NoSynchronization = 0,
  CSC_IfContainerIsSynchronized,
  CSC_NewSynchronizationIfNecessary,
  CSC_NewSynchronization
} CSC_SynchronizationConfig;