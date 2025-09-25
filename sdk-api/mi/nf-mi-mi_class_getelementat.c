MI_INLINE MI_Result MI_Class_GetElementAt(
  [in]            const MI_Class  *self,
                  MI_Uint32       index,
                  const MI_Char   **name,
  [out, optional] MI_Value        *value,
  [out, optional] MI_Boolean      *valueExists,
  [out, optional] MI_Type         *type,
                  MI_Char         **referenceClass,
  [out, optional] MI_QualifierSet *qualifierSet,
  [out, optional] MI_Uint32       *flags
);