MI_INLINE MI_Result MI_Deserializer_DeserializeClass(
  [in, out]       MI_Deserializer                   *deserializer,
                  MI_Uint32                         flags,
                  MI_Uint8                          *serializedBuffer,
                  MI_Uint32                         serializedBufferLength,
  [in, optional]  MI_Class                          *parentClass,
                  const MI_Char                     *serverName,
                  const MI_Char                     *namespaceName,
  [in, optional]  MI_Deserializer_ClassObjectNeeded classObjectNeeded,
  [in, out]       void                              *classObjectNeededContext,
  [out, optional] MI_Uint32                         *serializedBufferRead,
                  MI_Class                          **classObject,
                  MI_Instance                       **cimErrorDetails
);