typedef struct _D3DDDI_SYNCHRONIZATIONOBJECTINFO2 {
  D3DDDI_SYNCHRONIZATIONOBJECT_TYPE  Type;
  D3DDDI_SYNCHRONIZATIONOBJECT_FLAGS Flags;
  union {
    struct {
      BOOL InitialState;
    } SynchronizationMutex;
    struct {
      UINT MaxCount;
      UINT InitialCount;
    } Semaphore;
    struct {
      D3DKMT_ALIGN64 UINT64 FenceValue;
    } Fence;
    struct {
      HANDLE Event;
    } CPUNotification;
    struct {
      D3DKMT_ALIGN64 UINT64                 InitialFenceValue;
      VOID                                  *FenceValueCPUVirtualAddress;
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS FenceValueGPUVirtualAddress;
      UINT                                  EngineAffinity;
      UINT                                  Padding;
    } MonitoredFence;
    struct {
      D3DKMT_HANDLE                         hAdapter;
      D3DDDI_VIDEO_PRESENT_TARGET_ID        VidPnTargetId;
      D3DKMT_ALIGN64 UINT64                 Time;
      VOID                                  *FenceValueCPUVirtualAddress;
      D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS FenceValueGPUVirtualAddress;
      UINT                                  EngineAffinity;
      UINT                                  Padding;
    } PeriodicMonitoredFence;
    struct {
      D3DKMT_ALIGN64 UINT64 Reserved[8];
    } Reserved;
  };
  D3DKMT_HANDLE                      SharedHandle;
} D3DDDI_SYNCHRONIZATIONOBJECTINFO2;