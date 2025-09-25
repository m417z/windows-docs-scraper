MI_INLINE MI_Result MI_Session_Close(
  [in, out]      MI_Session                        *session,
  [in, optional] void                              *completionContext,
  [in, out]      void(* )(void *completionContext) completionCallback
);