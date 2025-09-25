typedef struct _MI_FeatureDecl {
  MI_Uint32             flags;
  MI_Uint32             code;
  MI_CONST MI_Char      *name;
  MI_Qualifier MI_CONST I_CONST * *Mqualifiers;
  MI_Uint32             numQualifiers;
} MI_FeatureDecl;