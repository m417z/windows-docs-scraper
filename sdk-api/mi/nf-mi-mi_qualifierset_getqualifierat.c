MI_INLINE MI_Result MI_QualifierSet_GetQualifierAt(
  [in]  const MI_QualifierSet *self,
        MI_Uint32             index,
        const MI_Char         **name,
  [out] MI_Type               *qualifierType,
  [out] MI_Uint32             *qualifierFlags,
  [out] MI_Value              *qualifierValue
);