typedef struct _MI_OperationOptionsFT {
  void()(MI_OperationOptions *options)      * Delete;
  MI_Result(MI_OperationOptions *options, const MI_Char *optionName, const MI_Char *value,MI_Uint32 flags) * )(SetString;
  MI_Result((MI_OperationOptions *options, const MI_Char *optionName,MI_Uint32 value,MI_Uint32 flags) * )SetNumber;
  MI_Result(MI_OperationOptions *options, const MI_Char *optionName,MI_Type valueType, const MI_Value *value,MI_Boolean mustComply,MI_Uint32 flags) * )(SetCustomOption;
  MI_Result(OperationOptions *options, const MI_Char *optionName, const MI_Char **value,MI_Uint32 *index,MI_Uint32 *flags) * )(MI_GetString;
  MI_Result(_OperationOptions *options, const MI_Char *optionName,MI_Uint32 *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetNumber;
  MI_Result((MI_OperationOptions *options,MI_Uint32 *count) * )GetOptionCount;
  MI_Result(OperationOptions *options,MI_Uint32 index, const MI_Char **optionName,MI_Value *value,MI_Type *type,MI_Uint32 *flags) * )(MI_GetOptionAt;
  MI_Result(OperationOptions *options, const MI_Char *optionName,MI_Value *value,MI_Type *type,MI_Uint32 *index,MI_Uint32 *flags) * )(MI_GetOption;
  MI_Result(_OperationOptions *options, const MI_Char *optionName,MI_Uint32 *channels,MI_Uint32 bufferLength,MI_Uint32 *channelCount,MI_Uint32 *flags) * )(MIGetEnabledChannels;
  MI_Result((const MI_OperationOptions *self,MI_OperationOptions *newOperationOptions) * )Clone;
  MI_Result(MI_OperationOptions *options, const MI_Char *optionName, const MI_Interval *value,MI_Uint32 flags) * )(SetInterval;
  MI_Result(_OperationOptions *options, const MI_Char *optionName,MI_Interval *value,MI_Uint32 *index,MI_Uint32 *flags) * )(MIGetInterval;
} MI_OperationOptionsFT;