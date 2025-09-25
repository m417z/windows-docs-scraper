typedef struct _MI_Server {
  const MI_ServerFT      *serverFT;
  const MI_ContextFT     *contextFT;
  const MI_InstanceFT    *instanceFT;
  const MI_PropertySetFT *propertySetFT;
  const MI_FilterFT      *filterFT;
} MI_Server;