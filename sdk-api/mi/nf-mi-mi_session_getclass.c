MI_INLINE void MI_Session_GetClass(
  [in]           MI_Session            *session,
                 MI_Uint32             flags,
  [in, optional] MI_OperationOptions   *options,
                 const MI_Char         *namespaceName,
                 const MI_Char         *className,
  [in, optional] MI_OperationCallbacks *callbacks,
  [out]          MI_Operation          *operation
);