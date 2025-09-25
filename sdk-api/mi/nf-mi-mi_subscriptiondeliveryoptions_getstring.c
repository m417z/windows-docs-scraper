MI_INLINE MI_Result MI_SubscriptionDeliveryOptions_GetString(
  [in]            MI_SubscriptionDeliveryOptions *self,
                  const MI_Char                  *optionName,
                  const MI_Char                  **value,
  [out, optional] MI_Uint32                      *index,
  [out, optional] MI_Uint32                      *flags
);