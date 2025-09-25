MI_INLINE MI_Result MI_SubscriptionDeliveryOptions_GetInterval(
  [in]            MI_SubscriptionDeliveryOptions *self,
                  const MI_Char                  *optionName,
  [out]           MI_Interval                    *value,
  [out, optional] MI_Uint32                      *index,
  [out, optional] MI_Uint32                      *flags
);