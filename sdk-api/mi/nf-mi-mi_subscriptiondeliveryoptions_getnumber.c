MI_INLINE MI_Result MI_SubscriptionDeliveryOptions_GetNumber(
  [in, out]       MI_SubscriptionDeliveryOptions *self,
                  const MI_Char                  *optionName,
  [out]           MI_Uint32                      *value,
  [out, optional] MI_Uint32                      *index,
  [out, optional] MI_Uint32                      *flags
);