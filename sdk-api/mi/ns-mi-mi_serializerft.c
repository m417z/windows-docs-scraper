typedef struct _MI_SerializerFT {
  MI_Result()(MI_Serializer *serializer) * Close;
  MI_Result(I_Serializer *serializer,MI_Uint32 flags, const MI_Class *classObject,MI_Uint8 *clientBuffer,MI_Uint32 clientBufferLength,MI_Uint32 *clientBufferNeeded) * )(MSerializeClass;
  MI_Result(I_Serializer *serializer,MI_Uint32 flags, const MI_Instance *instanceObject,MI_Uint8 *clientBuffer,MI_Uint32 clientBufferLength,MI_Uint32 *clientBufferNeeded) * )(MSerializeInstance;
} MI_SerializerFT;