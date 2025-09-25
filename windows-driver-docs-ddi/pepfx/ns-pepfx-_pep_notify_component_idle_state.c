typedef struct _PEP_NOTIFY_COMPONENT_IDLE_STATE {
  [in]  PEPHANDLE DeviceHandle;
  [in]  ULONG     Component;
  [in]  ULONG     IdleState;
  [in]  BOOLEAN   DriverNotified;
  [out] BOOLEAN   Completed;
} PEP_NOTIFY_COMPONENT_IDLE_STATE, *PPEP_NOTIFY_COMPONENT_IDLE_STATE;