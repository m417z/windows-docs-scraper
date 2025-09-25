MI_INLINE void MI_Session_EnumerateInstances(
  [in]           MI_Session            *session,
                 MI_Uint32             flags,
  [in, optional] MI_OperationOptions   *options,
                 const MI_Char         *namespaceName,
                 const MI_Char         *className,
                 MI_Boolean            keysOnly,
  [in, optional] MI_OperationCallbacks *callbacks,
  [out]          MI_Operation          *operation
);