# MI_Serializer_SerializeInstance function

## Description

Serializes an [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) into a buffer in the format specified when the serializer was created. Options can be passed into the flags to control if the class is also serialized into the buffer as well as the instance.

## Parameters

### `serializer` [in, out]

Serializer returned from [MI_Application_NewSerializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newserializer).

### `flags`

Must be either 0 or **MI_SERIALIZER_FLAGS_INSTANCE_WITH_CLASS**. 0 means to serialize the instance only. **MI_SERIALIZER_FLAGS_INSTANCE_WITH_CLASS** means to serialize the instance and all class parts into the buffer so that it is self contained.

### `instanceObject` [in]

Instance object to be serialized.

### `clientBuffer`

The output buffer to receive the serialized class data. If this parameter is **Null**, the required length of the buffer is passed back in *clientBufferNeeded*.

### `clientBufferLength`

Length of the *clientBuffer* passed in. If *clientBuffer* is **Null**, this parameter should be 0.

### `clientBufferNeeded` [in, out]

Returned total length the buffer needs to be. If a buffer is passed in (via the *clientBuffer* parameter) that is the required size or more, this value will indicate how much buffer was used. If a buffer was not passed in (where the *clientBuffer* value is **Null**) or the buffer is too small to hold the serialized class, this value will indicate how much space is needed to hold the serialized class.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## See also

[MI_Application_NewSerializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newserializer)