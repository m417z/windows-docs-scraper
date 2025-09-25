typedef struct tagUiInfo {
  UI_INFO_TYPE type;
  union {
    LPWSTR           pwzNull;
    ShellCommandInfo ShellInfo;
    LPWSTR           pwzHelpUrl;
    LPWSTR           pwzDui;
  };
} UiInfo, *PUiInfo;