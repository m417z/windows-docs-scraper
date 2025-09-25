# SetFactoid function

## Description

Specifies the factoid a recognizer uses to constrain its search for the result.

You specify a factoid if an input field is of a known type, such as if the input field contains a date. You call this function before processing the ink for the first time. Therefore, call the **SetFactoid** function before calling the [Process](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-process) function.

## Parameters

### `hrc`

Handle to the recognizer context.

### `cwcFactoid`

Number of characters in *pwcFactoid*.

### `pwcFactoid`

Identifies the factoid to use on the recognizer context. The string is not **NULL**-terminated.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TPC_E_INVALID_PROPERTY** | The specified factoid is not supported. |
| **TPC_E_OUT_OF_ORDER_CALL** | You must call the SetFactoid function before calling the Process function. |
| **E_POINTER** | The context is invalid or one of the parameters is an invalid pointer. |
| **E_NOTIMPL** | The recognizer does not support this function. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | The context contains an invalid value. |

## Remarks

For a list of factoids that can be passed in the *cwcFactoid* parameter, see [Supported Factoids from Version 1](https://learn.microsoft.com/windows/desktop/tablet/supported-factoids-from-version-1). The DEFAULT factoid listed in that topic is not a valid value to pass to **SetFactoid**; the Tablet PC Platform API's internally convert DEFAULT to **NULL** before calling the **SetFactoid** function.

It is recommended that you limit the length of the factoid string to no more than 32768 characters.

## See also

[SetFlags Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setflags)