HRESULT TaskDialog(
  [in]  HWND                           hwndOwner,
  [in]  HINSTANCE                      hInstance,
  [in]  PCWSTR                         pszWindowTitle,
  [in]  PCWSTR                         pszMainInstruction,
  [in]  PCWSTR                         pszContent,
  [in]  TASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons,
  [in]  PCWSTR                         pszIcon,
  [out] int                            *pnButton
);