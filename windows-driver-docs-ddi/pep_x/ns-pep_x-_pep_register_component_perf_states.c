typedef struct _PEP_REGISTER_COMPONENT_PERF_STATES {
  [in] PEPHANDLE                DeviceHandle;
  [in] ULONG                    Component;
  [in] ULONGLONG                Flags;
  [in] PPEP_COMPONENT_PERF_INFO PerfStateInfo;
} PEP_REGISTER_COMPONENT_PERF_STATES, *PPEP_REGISTER_COMPONENT_PERF_STATES;