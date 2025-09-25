# Tbsip_Cancel_Commands function

## Description

Cancels all outstanding commands for the specified context.

## Parameters

### `hContext` [in]

A TBS handle to the context whose commands are to be canceled and that was obtained from previous call to the [Tbsi_Context_Create](https://learn.microsoft.com/windows/desktop/api/tbs/nf-tbs-tbsi_context_create) function.

## Return value

If the function succeeds, the function returns TBS_SUCCESS.

If the function fails, it returns a TBS return code that indicates the error.

| Return code/value | Description |
| --- | --- |
| **TBS_SUCCESS**<br><br>0 (0x0) | The function was successful. |
| **TBS_E_INTERNAL_ERROR**<br><br>2150121473 (0x80284001) | An internal software error occurred. |
| **TBS_E_INVALID_CONTEXT**<br><br>2150121476 (0x80284004) | The specified context handle does not refer to a valid context. |
| **TBS_E_IOERROR**<br><br>2150121478 (0x80284006) | An error occurred while communicating with the TPM. |

## Remarks

When a command is canceled, TBS sends a message to the command that indicates that the command was canceled.