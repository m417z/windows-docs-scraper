# MI_Deserializer_DeserializeClass function

## Description

Deserializes a serialized buffer into an [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) object.

## Parameters

### `deserializer` [in, out]

A pointer to a deserializer object returned from a call to [MI_Application_NewDeserializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdeserializer). The deserializer must match the serializer that created the buffer.

### `flags`

This parameter must be 0.

### `serializedBuffer`

A serialized buffer that was filled via a call from [MI_Serializer_SerializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeclass).

### `serializedBufferLength`

The length of the buffer that was reported via a call to [MI_Serializer_SerializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeclass).

### `parentClass` [in, optional]

The parent class. If the class was not serialized with the class's parent class then this parameter needs to contain the [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) for the parent class. The parent class needs to contain all parent classes in the hierarchy. If the class was serialized with **MI_SERIALIZER_FLAGS_CLASS_DEEP** specified as a flag, then the parent class is not needed as it is a self-contained buffer, and **NULL** can be passed for this parameter.

### `serverName`

An optional, null-terminated string that represents the server name.

### `namespaceName`

An optional, null-terminated string that represents the namespace name.

### `classObjectNeeded` [in, optional]

A callback function used to provide a requested class object during deserialization.

### `classObjectNeededContext` [in, out]

A pointer to the context that is used with the callback function.

### `serializedBufferRead` [out, optional]

The amount of the serialized buffer that was read (deserialized).

### `classObject`

The returned deserialized class. This class needs to be deleted via [MI_Class_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_class_delete).

### `cimErrorDetails`

If the call fails, this value will contain information useful in debugging. This value must be deleted via [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete).

## Return value

This function returns MI_INLINE MI_Result.

## See also

[MI_Deserializer_ClassObjectNeeded](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nc-mi-mi_deserializer_classobjectneeded)