typedef struct _PEP_QUERY_COMPONENT_PERF_STATES {
  [in] PEPHANDLE       DeviceHandle;
  [in] ULONG           Component;
  [in] ULONG           Set;
  [in] PPEP_PERF_STATE States;
} PEP_QUERY_COMPONENT_PERF_STATES, *PPEP_QUERY_COMPONENT_PERF_STATES;