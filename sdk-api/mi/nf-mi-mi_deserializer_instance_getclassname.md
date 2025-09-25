# MI_Deserializer_Instance_GetClassName function

## Description

Gets the class name associated with the serialized instance.

## Parameters

### `deserializer` [in, out]

The deserializer to carry out the request.

### `serializedBuffer`

The serialized buffer to carry out the request.

### `serializedBufferLength`

The length of the serialized buffer.

### `className`

The output buffer that receives the class name.

### `classNameLength` [in, out]

The length of the class name buffer. After the function has completed, the value indicates how much buffer was used.

### `cimErrorDetails`

A pointer to the details of what went wrong. The object must be deleted with call to the [MI_Instance_Delete](https://learn.microsoft.com/previous-versions/windows/desktop/api/mi/nf-mi-mi_instance_delete) function.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.

## Remarks

Not all deserializers can support this call.