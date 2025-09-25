typedef struct _MI_ClassFT {
  MI_Result(const MI_Class *self, const MI_Char **className) * )(GetClassName;
  MI_Result(const MI_Class *self, const MI_Char **nameSpace) * )(GetNameSpace;
  MI_Result(const MI_Class *self, const MI_Char **serverName) * )(GetServerName;
  MI_Result((const MI_Class *self,MI_Uint32 *count) * )GetElementCount;
  MI_Result(I_Class *self, const MI_Char *name,MI_Value *value,MI_Boolean *valueExists,MI_Type *type,MI_Char **referenceClass,MI_QualifierSet *qualifierSet,MI_Uint32 *flags,MI_Uint32 *index) * )(const MGetElement;
  MI_Result(I_Class *self,MI_Uint32 index, const MI_Char **name,MI_Value *value,MI_Boolean *valueExists,MI_Type *type,MI_Char **referenceClass,MI_QualifierSet *qualifierSet,MI_Uint32 *flags) * )(const MGetElementAt;
  MI_Result((const MI_Class *self,MI_QualifierSet *qualifierSet) * )GetClassQualifierSet;
  MI_Result((const MI_Class *self,MI_Uint32 *count) * )GetMethodCount;
  MI_Result(nst MI_Class *self,MI_Uint32 index, const MI_Char **name,MI_QualifierSet *qualifierSet,MI_ParameterSet *parameterSet) * )(coGetMethodAt;
  MI_Result(nst MI_Class *self, const MI_Char *name,MI_QualifierSet *qualifierSet,MI_ParameterSet *parameterSet,MI_Uint32 *index) * )(coGetMethod;
  MI_Result(const MI_Class *self, const MI_Char **name) * )(GetParentClassName;
  MI_Result(const MI_Class *self,MI_Class **parentClass) * )(GetParentClass;
  MI_Result()(MI_Class *self) * Delete;
  MI_Result(const MI_Class *self,MI_Class **newClass) * )(Clone;
} MI_ClassFT;