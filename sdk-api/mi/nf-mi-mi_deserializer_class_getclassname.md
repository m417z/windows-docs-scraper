# MI_Deserializer_Class_GetClassName function

## Description

Gets the class name from a serialized class buffer.

## Parameters

### `deserializer` [in, out]

A pointer to a deserializer object returned from a call to [MI_Application_NewDeserializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdeserializer). The deserializer must match the serializer that created the buffer.

### `serializedBuffer`

A serialized byte[] buffer that was filled via a call from [MI_Serializer_SerializeInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeinstance).

### `serializedBufferLength`

The length of the buffer that was reported via a call to [MI_Serializer_SerializeInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeinstance).

### `className`

Returned class name. If this parameter is **Null**, the required buffer size is returned through the classNameLength parameter.

### `classNameLength` [in, out]

A pointer to the length of the *className* buffer. If *className* is **NULL**, this parameter is filled in with the required length of the buffer needed.

### `cimErrorDetails`

If the call fails, this value will contain information useful in debugging. This value must be deleted via [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete).

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Not all serializers include enough information to retrieve this information, in which case the function will fail with a **MI_RESULT_NOT_SUPPORTED** error.