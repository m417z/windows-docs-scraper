struct UIAutomationMethodInfo {
  LPCWSTR          pProgrammaticName;
  BOOL             doSetFocus;
  UINT             cInParameters;
  UINT             cOutParameters;
  UIAutomationType *pParameterTypes;
  LPCWSTR          *pParameterNames;
};