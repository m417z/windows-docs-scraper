MI_INLINE MI_Result MI_Serializer_SerializeInstance(
  [in, out] MI_Serializer     *serializer,
            MI_Uint32         flags,
  [in]      const MI_Instance *instanceObject,
            MI_Uint8          *clientBuffer,
            MI_Uint32         clientBufferLength,
  [in, out] MI_Uint32         *clientBufferNeeded
);