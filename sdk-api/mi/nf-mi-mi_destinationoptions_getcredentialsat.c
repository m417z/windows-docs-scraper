MI_INLINE MI_Result MI_DestinationOptions_GetCredentialsAt(
  [in]            MI_DestinationOptions *options,
                  MI_Uint32             index,
                  const MI_Char         **optionName,
  [out]           MI_UserCredentials    *credentials,
  [out, optional] MI_Uint32             *flags
);