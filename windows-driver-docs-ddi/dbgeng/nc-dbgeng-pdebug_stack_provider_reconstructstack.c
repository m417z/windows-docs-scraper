PDEBUG_STACK_PROVIDER_RECONSTRUCTSTACK PdebugStackProviderReconstructstack;

HRESULT PdebugStackProviderReconstructstack(
  [in]  ULONG SystemThreadId,
  [in]  PDEBUG_STACK_FRAME_EX NativeFrames,
  [in]  ULONG CountNativeFrames,
  [out] PSTACK_SYM_FRAME_INFO *StackSymFrames,
  [out] PULONG StackSymFramesFilled
)
{...}