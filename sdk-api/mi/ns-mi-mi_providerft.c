typedef struct _MI_ProviderFT {
  MI_ProviderFT_Load                Load;
  MI_ProviderFT_Unload              Unload;
  MI_ProviderFT_GetInstance         GetInstance;
  MI_ProviderFT_EnumerateInstances  EnumerateInstances;
  MI_ProviderFT_CreateInstance      CreateInstance;
  MI_ProviderFT_ModifyInstance      ModifyInstance;
  MI_ProviderFT_DeleteInstance      DeleteInstance;
  MI_ProviderFT_AssociatorInstances AssociatorInstances;
  MI_ProviderFT_ReferenceInstances  ReferenceInstances;
  MI_ProviderFT_EnableIndications   EnableIndications;
  MI_ProviderFT_DisableIndications  DisableIndications;
  MI_ProviderFT_Subscribe           Subscribe;
  MI_ProviderFT_Unsubscribe         Unsubscribe;
  MI_ProviderFT_Invoke              Invoke;
} MI_ProviderFT;