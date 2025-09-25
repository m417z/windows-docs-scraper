MI_INLINE MI_Result MI_Operation_GetIndication(
  [in]            MI_Operation      *operation,
                  const MI_Instance **instance,
                  const MI_Char     **bookmark,
                  const MI_Char     **machineID,
  [out, optional] MI_Boolean        *moreResults,
  [out, optional] MI_Result         *result,
                  const MI_Char     **errorMessage,
                  const MI_Instance **completionDetails
);