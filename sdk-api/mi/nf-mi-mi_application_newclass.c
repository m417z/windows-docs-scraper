MI_INLINE MI_Result MI_Application_NewClass(
  [in]           MI_Application     *application,
  [in]           const MI_ClassDecl *classDecl,
  [in, optional] const MI_Char      *namespaceName,
  [in, optional] const MI_Char      *serverName,
  [out]          MI_Class           **classObject
);