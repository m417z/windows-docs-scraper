typedef struct _MI_DestinationOptionsFT {
  void()(MI_DestinationOptions *options)      * Delete;
  MI_Result(MI_DestinationOptions *options, const MI_Char *optionName, const MI_Char *value,MI_Uint32 flags) * )(SetString;
  MI_Result((MI_DestinationOptions *options, const MI_Char *optionName,MI_Uint32 value,MI_Uint32 flags) * )SetNumber;
  MI_Result(MI_DestinationOptions *options, const MI_Char *optionName, const MI_UserCredentials *credentials,MI_Uint32 flags) * )(AddCredentials;
  MI_Result(DestinationOptions *options, const MI_Char *optionName, const MI_Char **value,MI_Uint32 *index,MI_Uint32 *flags) * )(MI_GetString;
  MI_Result(_DestinationOptions *options, const MI_Char *optionName,MI_Uint32 *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetNumber;
  MI_Result((MI_DestinationOptions *options,MI_Uint32 *count) * )GetOptionCount;
  MI_Result(DestinationOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_Value *value,MI_Type *type,MI_Uint32 *flags) * )(MI_GetOptionAt;
  MI_Result(DestinationOptions *options, const MI_Char *optionName,MI_Value *value,MI_Type *type,MI_Uint32 *index,MI_Uint32 *flags) * )(MI_GetOption;
  MI_Result((MI_DestinationOptions *options,MI_Uint32 *count) * )GetCredentialsCount;
  MI_Result(_DestinationOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_UserCredentials *credentials,MI_Uint32 *flags) * )(MIGetCredentialsAt;
  MI_Result(DestinationOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_Char *password,MI_Uint32 bufferLength,MI_Uint32 *passwordLength,MI_Uint32 *flags) * )(MI_GetCredentialsPasswordAt;
  MI_Result((const MI_DestinationOptions *self,MI_DestinationOptions *newDestinationOptions) * )Clone;
  MI_Result(MI_DestinationOptions *options, const MI_Char *optionName, const MI_Interval *value,MI_Uint32 flags) * )(SetInterval;
  MI_Result(_DestinationOptions *options, const MI_Char *optionName,MI_Interval *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetInterval;
} MI_DestinationOptionsFT;