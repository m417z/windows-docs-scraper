typedef struct _PEP_REQUEST_COMPONENT_PERF_STATE {
  [in]  PEPHANDLE                         DeviceHandle;
  [in]  ULONG                             Component;
  [out] BOOLEAN                           Completed;
  [out] BOOLEAN                           Succeeded;
  [in]  ULONG                             PerfRequestsCount;
  [in]  PPEP_COMPONENT_PERF_STATE_REQUEST PerfRequests;
} PEP_REQUEST_COMPONENT_PERF_STATE, *PPEP_REQUEST_COMPONENT_PERF_STATE;