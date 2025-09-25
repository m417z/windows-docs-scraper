MI_INLINE MI_Result MI_ParameterSet_GetParameterAt(
  [in]  const MI_ParameterSet *self,
        MI_Uint32             index,
        const MI_Char         **name,
  [out] MI_Type               *parameterType,
        MI_Char               **referenceClass,
  [out] MI_QualifierSet       *qualifierSet
);