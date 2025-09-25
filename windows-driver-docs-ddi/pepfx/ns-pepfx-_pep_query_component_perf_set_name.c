typedef struct _PEP_QUERY_COMPONENT_PERF_SET_NAME {
  [in]      PEPHANDLE DeviceHandle;
  [in]      ULONG     Component;
  [in]      ULONG     Set;
  [in, out] USHORT    NameSize;
  [in]      PWCHAR    Name;
} PEP_QUERY_COMPONENT_PERF_SET_NAME, *PPEP_QUERY_COMPONENT_PERF_SET_NAME;