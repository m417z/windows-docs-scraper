MI_INLINE MI_Result MI_OperationOptions_GetOption(
  [in]            MI_OperationOptions *options,
                  const MI_Char       *optionName,
  [out]           MI_Value            *value,
  [out]           MI_Type             *type,
  [out, optional] MI_Uint32           *index,
  [out, optional] MI_Uint32           *flags
);