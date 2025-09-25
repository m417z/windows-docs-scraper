# MI_Context_WriteStreamParameter function

## Description

Sends streamed parameter data to the client for a method invocation.

## Parameters

### `self` [in]

Request context.

### `name` [in]

A null-terminated string that represents the name of the method parameter to stream.

### `value` [in]

A value-type entity.

### `type` [in]

[MI_Type](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_type) object that indicates the type being
streamed.

### `flags` [in]

Must be 0 or
**MI_FLAG_NULL**.

#### MI_FLAG_NULL (0x20000000)

The end of the stream has been reached.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the
function return code. This can be one of the following codes.

## Remarks

Array-method out parameters can be marked as streamed, which means that instead of sending all out parameters
in one chunk they are streamed to the client. Streamed parameter data enables the client to display data in a
smoother fashion rather than having to wait until all of the data has been sent. This gives the user interface a
smoother, more consistent feel. The value can be an array that contains one or more elements of the specified
type. Call this function repeatedly to send the entire stream. If the client does not handle streamed parameters,
the server will cache all the results and send them to the client at once. In the case of the results being cached
when large result sets are generated, the provider may exceed quotas and be shutdown, meaning that methods that
generate very large result sets may work only with clients that support streaming.

## See also

[MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context)

[MI_Type](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_type)