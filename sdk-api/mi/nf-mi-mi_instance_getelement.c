MI_INLINE MI_Result MI_INLINE_CALL MI_Instance_GetElement(
  [in]            const MI_Instance *self,
                  const MI_Char     *name,
  [out, optional] MI_Value          *value,
  [out, optional] MI_Type           *type,
  [out, optional] MI_Uint32         *flags,
  [out, optional] MI_Uint32         *index
);