typedef struct _MI_QualifierDecl {
  MI_CONST MI_Char *name;
  MI_Uint32        type;
  MI_Uint32        scope;
  MI_Uint32        flavor;
  MI_Uint32        subscript;
  MI_CONST void    *value;
} MI_QualifierDecl;