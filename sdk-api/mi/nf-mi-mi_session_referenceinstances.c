MI_INLINE void MI_Session_ReferenceInstances(
  [in]           MI_Session            *session,
                 MI_Uint32             flags,
  [in, optional] MI_OperationOptions   *options,
                 const MI_Char         *namespaceName,
  [in]           const MI_Instance     *instanceKey,
                 const MI_Char         *resultClass,
                 const MI_Char         *role,
                 MI_Boolean            keysOnly,
  [in, optional] MI_OperationCallbacks *callbacks,
  [out]          MI_Operation          *operation
);