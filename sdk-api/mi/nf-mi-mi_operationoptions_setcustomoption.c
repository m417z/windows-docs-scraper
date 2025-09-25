MI_INLINE MI_Result MI_OperationOptions_SetCustomOption(
  [in, out] MI_OperationOptions *options,
            const MI_Char       *optionName,
  [in]      MI_Type             optionValueType,
  [in]      const MI_Value      *optionValue,
            MI_Boolean          mustComply
);