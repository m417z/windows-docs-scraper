typedef struct _MI_PropertyDecl {
  MI_Uint32             flags;
  MI_Uint32             code;
  MI_CONST MI_Char      *name;
  MI_Qualifier MI_CONST I_CONST * *Mqualifiers;
  MI_Uint32             numQualifiers;
  MI_Uint32             type;
  MI_CONST MI_Char      *className;
  MI_Uint32             subscript;
  MI_Uint32             offset;
  MI_CONST MI_Char      *origin;
  MI_CONST MI_Char      *propagator;
  MI_CONST void         *value;
} MI_PropertyDecl;