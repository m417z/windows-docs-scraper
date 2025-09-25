typedef struct _MI_SchemaDecl {
  MI_QualifierDecl MI_CONST I_CONST * *MqualifierDecls;
  MI_Uint32                 numQualifierDecls;
  MI_ClassDecl MI_CONST I_CONST *     *MclassDecls;
  MI_Uint32                 numClassDecls;
} MI_SchemaDecl;