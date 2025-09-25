HRESULT SetScope(
  [in]           ULONG64            InstructionOffset,
  [in, optional] PDEBUG_STACK_FRAME ScopeFrame,
  [in, optional] PVOID              ScopeContext,
  [in]           ULONG              ScopeContextSize
);