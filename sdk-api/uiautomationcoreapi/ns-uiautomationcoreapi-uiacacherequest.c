struct UiaCacheRequest {
  struct UiaCondition   *pViewCondition;
  TreeScope             Scope;
  PROPERTYID            *pProperties;
  int                   cProperties;
  PATTERNID             *pPatterns;
  int                   cPatterns;
  AutomationElementMode automationElementMode;
};