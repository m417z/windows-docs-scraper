typedef struct _MI_Module {
  MI_Uint32           version;
  MI_Uint32           generatorVersion;
  MI_Uint32           flags;
  MI_Uint32           charSize;
  MI_SchemaDecl       *schemaDecl;
  MI_Module_Load      Load;
  MI_Module_Unload    Unload;
  const MI_ProviderFT *dynamicProviderFT;
} MI_Module;