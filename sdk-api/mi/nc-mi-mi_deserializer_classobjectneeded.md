## Description

Used to provide requested class object during deserialization.

## Parameters

### `context` [in, optional]

A pointer to the context.

### `serverName` [in, optional]

The name of the server.

### `namespaceName` [in, optional]

The namespace of the object.

### `className` [in, optional]

The class of the object.

### `requestedClassObject` [out]

A [MI_Class](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_class) representing the requested class object.

## Return value

Returns a [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) indicating the status of the operation.

## See also

[MI_DeserializerFT](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_deserializerft)

[MI_Deserializer_DeserializeClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_deserializeclass)

[MI_Deserializer_DeserializeInstance](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_deserializer_deserializeinstance)