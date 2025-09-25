NTSTATUS CmSetCallbackObjectContext(
  [in, out]       PVOID          Object,
  [in]            PLARGE_INTEGER Cookie,
  [in]            PVOID          NewContext,
  [out, optional] PVOID          *OldContext
);