PVOID WINAPI ResolveDelayLoadedAPI(
  _In_       PVOID                             ParentModuleBase,
  _In_       PCIMAGE_DELAYLOAD_DESCRIPTOR      DelayloadDescriptor,
  _In_opt_   PDELAYLOAD_FAILURE_DLL_CALLBACK   FailureDllHook,
  _In_opt_   PDELAYLOAD_FAILURE_SYSTEM_ROUTINE FailureSystemHook,
  _Out_      PIMAGE_THUNK_DATA                 ThunkAddress,
  _Reserved_ ULONG                             Flags
);