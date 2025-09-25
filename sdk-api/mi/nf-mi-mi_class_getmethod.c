MI_INLINE MI_Result MI_Class_GetMethod(
  [in]            const MI_Class  *self,
  [in]            const MI_Char   *name,
  [out, optional] MI_QualifierSet *qualifierSet,
  [out, optional] MI_ParameterSet *parameterSet,
  [out, optional] MI_Uint32       *index
);