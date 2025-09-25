typedef struct _TASKDIALOGCONFIG {
  UINT                           cbSize;
  HWND                           hwndParent;
  HINSTANCE                      hInstance;
  TASKDIALOG_FLAGS               dwFlags;
  TASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons;
  PCWSTR                         pszWindowTitle;
  union {
    HICON  hMainIcon;
    PCWSTR pszMainIcon;
  } DUMMYUNIONNAME;
  PCWSTR                         pszMainInstruction;
  PCWSTR                         pszContent;
  UINT                           cButtons;
  const TASKDIALOG_BUTTON        *pButtons;
  int                            nDefaultButton;
  UINT                           cRadioButtons;
  const TASKDIALOG_BUTTON        *pRadioButtons;
  int                            nDefaultRadioButton;
  PCWSTR                         pszVerificationText;
  PCWSTR                         pszExpandedInformation;
  PCWSTR                         pszExpandedControlText;
  PCWSTR                         pszCollapsedControlText;
  union {
    HICON  hFooterIcon;
    PCWSTR pszFooterIcon;
  } DUMMYUNIONNAME2;
  PCWSTR                         pszFooter;
  PFTASKDIALOGCALLBACK           pfCallback;
  LONG_PTR                       lpCallbackData;
  UINT                           cxWidth;
} TASKDIALOGCONFIG;