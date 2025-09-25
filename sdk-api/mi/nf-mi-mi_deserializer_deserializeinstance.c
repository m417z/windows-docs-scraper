MI_INLINE MI_Result MI_Deserializer_DeserializeInstance(
  [in, out]       MI_Deserializer                   *deserializer,
                  MI_Uint32                         flags,
                  MI_Uint8                          *serializedBuffer,
                  MI_Uint32                         serializedBufferLength,
                  MI_Class                          **classObjects,
                  MI_Uint32                         numberClassObjects,
  [in, optional]  MI_Deserializer_ClassObjectNeeded classObjectNeeded,
  [in, out]       void                              *classObjectNeededContext,
  [out, optional] MI_Uint32                         *serializedBufferRead,
                  MI_Instance                       **instanceObject,
                  MI_Instance                       **cimErrorDetails
);