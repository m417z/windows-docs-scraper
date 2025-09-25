MI_INLINE void MI_Session_CreateInstance(
  [in]           MI_Session            *session,
                 MI_Uint32             flags,
  [in, optional] MI_OperationOptions   *options,
                 const MI_Char         *namespaceName,
  [in]           const MI_Instance     *inboundInstance,
  [in, optional] MI_OperationCallbacks *callbacks,
  [out]          MI_Operation          *operation
);