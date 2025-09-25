HRESULT RegisterTaskDefinition(
  [in]           BSTR            path,
  [in]           ITaskDefinition *pDefinition,
  [in]           LONG            flags,
  [in]           VARIANT         userId,
  [in]           VARIANT         password,
  [in]           TASK_LOGON_TYPE logonType,
  [in, optional] VARIANT         sddl,
  [out]          IRegisteredTask **ppTask
);