typedef struct _MI_ObjectDecl {
  MI_Uint32                 flags;
  MI_Uint32                 code;
  MI_CONST MI_Char          *name;
  MI_Qualifier MI_CONST I_CONST *     *Mqualifiers;
  MI_Uint32                 numQualifiers;
  _MI_PropertyDecl MI_CONST I_CONST * *Mproperties;
  struct                    _MI_PropertyDecl;
  MI_Uint32                 numProperties;
  MI_Uint32                 size;
} MI_ObjectDecl;