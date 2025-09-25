MI_INLINE MI_Result MI_Deserializer_Class_GetParentClassName(
  [in, out] MI_Deserializer *deserializer,
            MI_Uint8        *serializedBuffer,
            MI_Uint32       serializedBufferLength,
            MI_Char         *parentClassName,
  [in, out] MI_Uint32       *parentClassNameLength,
            MI_Instance     **cimErrorDetails
);