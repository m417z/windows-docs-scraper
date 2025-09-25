typedef struct _D3DDDI_SYNCHRONIZATIONOBJECTINFO {
  [in] D3DDDI_SYNCHRONIZATIONOBJECT_TYPE Type;
  union {
    struct {
      BOOL InitialState;
    } SynchronizationMutex;
    struct {
      UINT MaxCount;
      UINT InitialCount;
    } Semaphore;
    struct {
      UINT Reserved[16];
    } Reserved;
  };
} D3DDDI_SYNCHRONIZATIONOBJECTINFO;