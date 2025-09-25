BOOL QueryUmsThreadInformation(
  [in]            PUMS_CONTEXT          UmsThread,
  [in]            UMS_THREAD_INFO_CLASS UmsThreadInfoClass,
  [out]           PVOID                 UmsThreadInformation,
  [in]            ULONG                 UmsThreadInformationLength,
  [out, optional] PULONG                ReturnLength
);