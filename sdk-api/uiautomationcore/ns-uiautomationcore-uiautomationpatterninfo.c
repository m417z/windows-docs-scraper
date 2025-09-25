struct UIAutomationPatternInfo {
  GUID                            guid;
  LPCWSTR                         pProgrammaticName;
  GUID                            providerInterfaceId;
  GUID                            clientInterfaceId;
  UINT                            cProperties;
  struct UIAutomationPropertyInfo *pProperties;
  UINT                            cMethods;
  struct UIAutomationMethodInfo   *pMethods;
  UINT                            cEvents;
  struct UIAutomationEventInfo    *pEvents;
  IUIAutomationPatternHandler     *pPatternHandler;
};