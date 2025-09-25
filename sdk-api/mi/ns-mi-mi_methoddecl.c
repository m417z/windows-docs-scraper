typedef struct _MI_MethodDecl {
  MI_Uint32                  flags;
  MI_Uint32                  code;
  MI_CONST MI_Char           *name;
  _MI_Qualifier MI_CONST I_CONST *     *Mqualifiers;
  struct                     _MI_Qualifier;
  MI_Uint32                  numQualifiers;
  _MI_ParameterDecl MI_CONST I_CONST * *Mparameters;
  struct                     _MI_ParameterDecl;
  MI_Uint32                  numParameters;
  MI_Uint32                  size;
  MI_Uint32                  returnType;
  MI_CONST MI_Char           *origin;
  MI_CONST MI_Char           *propagator;
  _MI_SchemaDecl MI_CONST    *schema;
  struct                     _MI_SchemaDecl;
  MI_MethodDecl_Invoke       function;
} MI_MethodDecl;