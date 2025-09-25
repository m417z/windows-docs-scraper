HRESULT CreateSyncSemaphore(
  REFGUID             kseventSet,
  ULONG               kseventId,
  ULONG               kseventFlags,
  HANDLE              semaphoreHandle,
  LONG                semaphoreAdjustment,
  IMFCameraSyncObject **cameraSyncObject
);