typedef struct _MI_QualifierSetFT {
  MI_Result((const MI_QualifierSet *self,MI_Uint32 *count) * )GetQualifierCount;
  MI_Result(st MI_QualifierSet *self,MI_Uint32 index, const MI_Char **name,MI_Type *qualifierType,MI_Uint32 *qualifierFlags,MI_Value *qualifierValue) * )(conGetQualifierAt;
  MI_Result(st MI_QualifierSet *self, const MI_Char *name,MI_Type *qualifierType,MI_Uint32 *qualifierFlags,MI_Value *qualifierValue,MI_Uint32 *index) * )(conGetQualifier;
} MI_QualifierSetFT;