typedef struct _MI_FilterFT {
  MI_Result(const MI_Filter *self, const MI_Instance *instance,MI_Boolean *result) * )(Evaluate;
  MI_Result(nst MI_Filter *self, const MI_Char **queryLang, const MI_Char **queryExpr) * )(coGetExpression;
} MI_FilterFT;