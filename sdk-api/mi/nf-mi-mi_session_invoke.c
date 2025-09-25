MI_INLINE void MI_Session_Invoke(
  [in]           MI_Session            *session,
                 MI_Uint32             flags,
  [in, optional] MI_OperationOptions   *options,
  [in, optional] const MI_Char         *namespaceName,
  [in, optional] const MI_Char         *className,
  [in]           const MI_Char         *methodName,
  [in, optional] const MI_Instance     *inboundInstance,
  [in, optional] const MI_Instance     *inboundProperties,
  [in, optional] MI_OperationCallbacks *callbacks,
  [out]          MI_Operation          *operation
);