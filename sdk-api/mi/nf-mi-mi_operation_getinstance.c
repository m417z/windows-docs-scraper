MI_INLINE MI_Result MI_Operation_GetInstance(
  [in]            MI_Operation      *operation,
                  const MI_Instance **instance,
  [out, optional] MI_Boolean        *moreResults,
  [out, optional] MI_Result         *result,
                  const MI_Char     **errorMessage,
                  const MI_Instance **completionDetails
);