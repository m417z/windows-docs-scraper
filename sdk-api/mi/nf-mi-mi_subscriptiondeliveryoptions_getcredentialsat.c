MI_INLINE MI_Result MI_SubscriptionDeliveryOptions_GetCredentialsAt(
  [in]            MI_SubscriptionDeliveryOptions *self,
                  MI_Uint32                      index,
                  const MI_Char                  **optionName,
  [out]           MI_UserCredentials             *credentials,
  [out, optional] MI_Uint32                      *flags
);