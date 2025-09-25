typedef struct _MI_ParameterSetFT {
  MI_Result(const MI_ParameterSet *self,MI_Type *returnType,MI_QualifierSet *qualifierSet) * )(GetMethodReturnType;
  MI_Result((const MI_ParameterSet *self,MI_Uint32 *count) * )GetParameterCount;
  MI_Result(t MI_ParameterSet *self,MI_Uint32 index, const MI_Char **name,MI_Type *parameterType,MI_Char **referenceClass,MI_QualifierSet *qualifierSet) * )(consGetParameterAt;
  MI_Result(t MI_ParameterSet *self, const MI_Char *name,MI_Type *parameterType,MI_Char **referenceClass,MI_QualifierSet *qualifierSet,MI_Uint32 *index) * )(consGetParameter;
} MI_ParameterSetFT;