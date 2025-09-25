NTSTATUS CmRegisterCallbackEx(
  [in]           PEX_CALLBACK_FUNCTION Function,
  [in]           PCUNICODE_STRING      Altitude,
  [in]           PVOID                 Driver,
  [in, optional] PVOID                 Context,
  [out]          PLARGE_INTEGER        Cookie,
                 PVOID                 Reserved
);