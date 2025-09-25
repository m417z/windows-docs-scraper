NTSTATUS CmRegisterCallback(
  [in]           PEX_CALLBACK_FUNCTION Function,
  [in, optional] PVOID                 Context,
  [out]          PLARGE_INTEGER        Cookie
);