typedef enum _WDF_SYNCHRONIZATION_SCOPE {
  WdfSynchronizationScopeInvalid = 0x00,
  WdfSynchronizationScopeInheritFromParent,
  WdfSynchronizationScopeDevice,
  WdfSynchronizationScopeQueue,
  WdfSynchronizationScopeNone
} WDF_SYNCHRONIZATION_SCOPE;