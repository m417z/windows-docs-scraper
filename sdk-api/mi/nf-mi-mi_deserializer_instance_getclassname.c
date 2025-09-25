MI_INLINE MI_Result MI_Deserializer_Instance_GetClassName(
  [in, out] MI_Deserializer *deserializer,
            MI_Uint8        *serializedBuffer,
            MI_Uint32       serializedBufferLength,
            MI_Char         *className,
  [in, out] MI_Uint32       *classNameLength,
            MI_Instance     **cimErrorDetails
);