HRESULT SetScopeEx(
  [in]           ULONG64               InstructionOffset,
  [in, optional] PDEBUG_STACK_FRAME_EX ScopeFrame,
  [in]           PVOID                 ScopeContext,
  [in]           ULONG                 ScopeContextSize
);