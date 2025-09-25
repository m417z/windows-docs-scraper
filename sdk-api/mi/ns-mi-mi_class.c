typedef struct _MI_Class {
  const MI_ClassFT      *ft;
  MI_CONST MI_ClassDecl *classDecl;
  MI_CONST MI_Char      *namespaceName;
  MI_CONST MI_Char      *serverName;
  ptrdiff_t             reserved[4];
} MI_Class;