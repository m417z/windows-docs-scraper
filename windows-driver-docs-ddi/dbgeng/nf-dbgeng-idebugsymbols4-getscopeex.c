HRESULT GetScopeEx(
  [out, optional] PULONG64              InstructionOffset,
  [out, optional] PDEBUG_STACK_FRAME_EX ScopeFrame,
  [out]           PVOID                 ScopeContext,
  [in]            ULONG                 ScopeContextSize
);