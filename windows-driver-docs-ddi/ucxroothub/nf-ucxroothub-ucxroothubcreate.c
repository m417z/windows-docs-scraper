NTSTATUS UcxRootHubCreate(
  [in]           UCXCONTROLLER          Controller,
  [in]           PUCX_ROOTHUB_CONFIG    Config,
  [in, optional] PWDF_OBJECT_ATTRIBUTES Attributes,
  [out]          UCXROOTHUB             *RootHub
);