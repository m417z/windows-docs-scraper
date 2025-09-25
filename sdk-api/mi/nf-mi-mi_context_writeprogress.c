MI_INLINE MI_Result MI_INLINE_CALL MI_Context_WriteProgress(
  [in] MI_Context    *context,
  [in] const MI_Char *activity,
  [in] const MI_Char *currentOperation,
  [in] const MI_Char *statusDescription,
       MI_Uint32     percentComplete,
       MI_Uint32     secondsRemaining
);