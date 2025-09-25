MI_INLINE MI_Result MI_INLINE_CALL MI_Context_GetCustomOptionAt(
  [in]            MI_Context    *context,
  [in]            MI_Uint32     index,
                  const MI_Char **name,
  [out, optional] MI_Type       *valueType,
  [out, optional] MI_Value      *value
);