MI_INLINE MI_Result MI_OperationOptions_GetEnabledChannels(
  [in]            MI_OperationOptions *options,
                  MI_Uint32           *channels,
  [in]            MI_Uint32           bufferLength,
  [out]           MI_Uint32           *channelCount,
  [out, optional] MI_Uint32           *flags
);