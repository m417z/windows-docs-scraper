typedef struct _MI_ClientFT_V1 {
  const MI_ApplicationFT                 *applicationFT;
  const MI_SessionFT                     *sessionFT;
  const MI_OperationFT                   *operationFT;
  const MI_HostedProviderFT              *hostedProviderFT;
  const MI_SerializerFT                  *serializerFT;
  const MI_DeserializerFT                *deserializerFT;
  const MI_SubscriptionDeliveryOptionsFT *subscribeDeliveryOptionsFT;
  const MI_DestinationOptionsFT          *destinationOptionsFT;
  const MI_OperationOptionsFT            *operationOptionsFT;
  const MI_UtilitiesFT                   *utilitiesFT;
} MI_ClientFT_V1;