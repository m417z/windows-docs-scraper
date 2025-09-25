MI_INLINE MI_Result MI_DestinationOptions_GetCredentialsPasswordAt(
  [in]            MI_DestinationOptions *options,
                  MI_Uint32             index,
                  const MI_Char         **optionName,
                  MI_Char               *password,
  [in]            MI_Uint32             bufferLength,
  [out]           MI_Uint32             *passwordLength,
  [out, optional] MI_Uint32             *flags
);