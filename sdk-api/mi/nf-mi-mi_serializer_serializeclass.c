MI_INLINE MI_Result MI_Serializer_SerializeClass(
  [in, out] MI_Serializer  *serializer,
            MI_Uint32      flags,
  [in]      const MI_Class *classObject,
            MI_Uint8       *clientBuffer,
            MI_Uint32      clientBufferLength,
  [in, out] MI_Uint32      *clientBufferNeeded
);