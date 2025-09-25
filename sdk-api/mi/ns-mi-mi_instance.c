typedef struct _MI_Instance {
  const MI_InstanceFT *ft;
  const MI_ClassDecl  *classDecl;
  const MI_Char       *serverName;
  const MI_Char       *nameSpace;
  ptrdiff_t           reserved[4];
} MI_Instance;