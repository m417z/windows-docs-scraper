MI_INLINE MI_Result MI_SubscriptionDeliveryOptions_GetCredentialsPasswordAt(
  [in]            MI_SubscriptionDeliveryOptions *self,
                  MI_Uint32                      index,
                  const MI_Char                  **optionName,
                  MI_Char                        *password,
  [in]            MI_Uint32                      bufferLength,
  [out]           MI_Uint32                      *passwordLength,
  [out, optional] MI_Uint32                      *flags
);