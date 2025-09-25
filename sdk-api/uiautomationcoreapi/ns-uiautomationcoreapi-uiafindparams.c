struct UiaFindParams {
  int                 MaxDepth;
  BOOL                FindFirst;
  BOOL                ExcludeRoot;
  struct UiaCondition *pFindCondition;
};