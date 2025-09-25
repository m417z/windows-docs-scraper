NTSTATUS ExCreateCallback(
  [out] PCALLBACK_OBJECT   *CallbackObject,
  [in]  POBJECT_ATTRIBUTES ObjectAttributes,
  [in]  BOOLEAN            Create,
  [in]  BOOLEAN            AllowMultipleCallbacks
);