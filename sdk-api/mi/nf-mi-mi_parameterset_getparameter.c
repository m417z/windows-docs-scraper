MI_INLINE MI_Result MI_ParameterSet_GetParameter(
  [in]  const MI_ParameterSet *self,
  [in]  const MI_Char         *name,
  [out] MI_Type               *parameterType,
  [out] MI_Char               **referenceClass,
  [out] MI_QualifierSet       *qualifierSet,
  [out] MI_Uint32             *index
);