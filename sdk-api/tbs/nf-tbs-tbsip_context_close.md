# Tbsip_Context_Close function

## Description

Closes a context handle, which releases resources associated with the context in TBS and closes the binding handle used to communicate with TBS.

## Parameters

### `hContext` [in]

A handle of the context to be closed.

## Return value

If the function succeeds, the function returns TBS_SUCCESS.

If the function fails, it returns a TBS return code that indicates the error.

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function was successful. |
| **TBS_E_INTERNAL_ERROR**<br><br>2150121473 (0x80284001) | An internal software error occurred. |
| **TBS_E_INVALID_CONTEXT**<br><br>2150121476 (0x80284004) | The specified context handle does not refer to a valid context. |

## Remarks

When the context handle is closed, the structure associated with the context handle is zeroed, which ensures that subsequent attempts to use the handle will result in an error. All objects that have been created under this context will be flushed.