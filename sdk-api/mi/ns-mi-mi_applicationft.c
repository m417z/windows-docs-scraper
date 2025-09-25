typedef struct _MI_ApplicationFT {
  MI_Result()(MI_Application *application) * Close;
  MI_Result(plication *application, const MI_Char *protocol, const MI_Char *destination,MI_DestinationOptions *options,MI_SessionCallbacks *callbacks,MI_Instance **extendedError,MI_Session *session) * )(MI_ApNewSession;
  MI_Result(Application *application, const MI_Char *namespaceName, const MI_Char *providerName,MI_MainFunction mi_Main,MI_Instance **extendedError,MI_HostedProvider *provider) * )(MI_NewHostedProvider;
  MI_Result(_Application *application, const MI_Char *className, const MI_ClassDecl *classRTTI,MI_Instance **instance) * )(MINewInstance;
  MI_Result((MI_Application *application,MI_DestinationOptions *options) * )NewDestinationOptions;
  MI_Result((MI_Application *application,MI_Boolean customOptionsMustUnderstand,MI_OperationOptions *options) * )NewOperationOptions;
  MI_Result((MI_Application *application,MI_SubscriptionDeliveryType deliveryType,MI_SubscriptionDeliveryOptions *deliveryOptions) * )NewSubscriptionDeliveryOptions;
  MI_Result(MI_Application *application,MI_Uint32 flags,MI_Char *format,MI_Serializer *serializer) * )(NewSerializer;
  MI_Result(MI_Application *application,MI_Uint32 flags,MI_Char *format,MI_Deserializer *deserializer) * )(NewDeserializer;
  MI_Result(_Application *application, const MI_Char *className, const MI_Class *classObject,MI_Instance **instance) * )(MINewInstanceFromClass;
  MI_Result(Application *application, const MI_ClassDecl *classDecl, const MI_Char *namespaceName, const MI_Char *serverName,MI_Class **classObject) * )(MI_NewClass;
} MI_ApplicationFT;