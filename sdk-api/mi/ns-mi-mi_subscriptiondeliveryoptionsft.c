typedef struct _MI_SubscriptionDeliveryOptionsFT {
  MI_Result(MI_SubscriptionDeliveryOptions *options, const MI_Char *optionName, const MI_Char *value,MI_Uint32 flags) * )(SetString;
  MI_Result((MI_SubscriptionDeliveryOptions *options, const MI_Char *optionName,MI_Uint32 value,MI_Uint32 flags) * )SetNumber;
  MI_Result(MI_SubscriptionDeliveryOptions *options, const MI_Char *optionName, const MI_Datetime *value,MI_Uint32 flags) * )(SetDateTime;
  MI_Result(MI_SubscriptionDeliveryOptions *options, const MI_Char *optionName, const MI_Interval *value,MI_Uint32 flags) * )(SetInterval;
  MI_Result(MI_SubscriptionDeliveryOptions *options, const MI_Char *optionName, const MI_UserCredentials *credentials,MI_Uint32 flags) * )(AddCredentials;
  MI_Result()(MI_SubscriptionDeliveryOptions *self) * Delete;
  MI_Result(SubscriptionDeliveryOptions *options, const MI_Char *optionName, const MI_Char **value,MI_Uint32 *index,MI_Uint32 *flags) * )(MI_GetString;
  MI_Result(_SubscriptionDeliveryOptions *options, const MI_Char *optionName,MI_Uint32 *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetNumber;
  MI_Result(_SubscriptionDeliveryOptions *options, const MI_Char *optionName,MI_Datetime *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetDateTime;
  MI_Result(_SubscriptionDeliveryOptions *options, const MI_Char *optionName,MI_Interval *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetInterval;
  MI_Result((MI_SubscriptionDeliveryOptions *options,MI_Uint32 *count) * )GetOptionCount;
  MI_Result(SubscriptionDeliveryOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_Value *value,MI_Type *type,MI_Uint32 *flags) * )(MI_GetOptionAt;
  MI_Result(SubscriptionDeliveryOptions *options, const MI_Char *optionName,MI_Value *value,MI_Type *type,MI_Uint32 *index,MI_Uint32 *flags) * )(MI_GetOption;
  MI_Result((MI_SubscriptionDeliveryOptions *options,MI_Uint32 *count) * )GetCredentialsCount;
  MI_Result(_SubscriptionDeliveryOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_UserCredentials *credentials,MI_Uint32 *flags) * )(MIGetCredentialsAt;
  MI_Result(SubscriptionDeliveryOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_Char *password,MI_Uint32 bufferLength,MI_Uint32 *passwordLength,MI_Uint32 *flags) * )(MI_GetCredentialsPasswordAt;
  MI_Result((const MI_SubscriptionDeliveryOptions *self,MI_SubscriptionDeliveryOptions *newSubscriptionDeliveryOptions) * )Clone;
} MI_SubscriptionDeliveryOptionsFT;