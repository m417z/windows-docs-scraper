# MI_Deserializer_DeserializeInstance function

## Description

Deserializes a serialized buffer into a [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) object.

## Parameters

### `deserializer` [in, out]

A pointer to a deserializer object returned from a call to [MI_Application_NewDeserializer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_application_newdeserializer). The deserializer must match the serializer that created the buffer.

### `flags`

This parameter must be 0.

### `serializedBuffer`

A serialized buffer that was filled via a call from [MI_Serializer_SerializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeclass).

### `serializedBufferLength`

The length of the buffer that was reported via a call to [MI_Serializer_SerializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_serializer_serializeclass).

### `classObjects`

If the instance was serialized without class details, an array of pointers to all classes needed to rebuild the instance is needed. Otherwise, **NULL** can be passed.

### `numberClassObjects`

Number of class objects in the *classObjects* array.

### `classObjectNeeded` [in, optional]

A callback function used to provide a requested class object during deserialization. See [MI_Deserializer_ClassObjectNeeded](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nc-mi-mi_deserializer_classobjectneeded).

### `classObjectNeededContext` [in, out]

A pointer to the context that is used with the callback function.

### `serializedBufferRead` [out, optional]

The amount of the serialized buffer that was read (deserialized).

### `instanceObject`

The returned deserialized instance. This class needs to be deleted via [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete).

### `cimErrorDetails`

If the call fails, this value will contain information useful in debugging. This value must be deleted via [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete).

## Return value

This function returns MI_INLINE MI_Result.

## Remarks

Deserializing instances that have embedded object and reference object properties are a little more complex when the serialized instance does not have the class definition included in the serialized blob. When the class definition is included with the instance, this problem does not arise. When no class is given, the instance deserializer needs the pass the instance class, along with the class definitions for all embedded object and reference object properties. They can be included through the *classObjects* array parameter, or they can be queried for via the *classObjectNeeded* callback.