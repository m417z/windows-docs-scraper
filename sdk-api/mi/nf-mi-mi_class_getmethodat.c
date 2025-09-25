MI_INLINE MI_Result MI_Class_GetMethodAt(
  [in]            const MI_Class  *self,
                  MI_Uint32       index,
                  const MI_Char   **name,
  [out, optional] MI_QualifierSet *qualifierSet,
  [out, optional] MI_ParameterSet *parameterSet
);