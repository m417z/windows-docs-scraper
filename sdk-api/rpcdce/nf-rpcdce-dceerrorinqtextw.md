# DceErrorInqTextW function

## Description

The
**DceErrorInqText** function returns the message text for a status code.

## Parameters

### `RpcStatus`

Status code to convert to a text string.

### `ErrorText`

Returns the text corresponding to the error code.

| Value | Meaning |
| --- | --- |
| **RPC_S_OK** | The call succeeded. |
| **RPC_S_INVALID_ARG** | Unknown error code. |

## Return value

This function returns RPC_S_OK if it is successful, or an error code if not.

**Note** For a list of valid error codes, see
[RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

## Remarks

The
**DceErrorInqText** routine fills the string pointed to by the *ErrorText* parameter with a null-terminated character string message for a particular status code.

> [!NOTE]
> The rpcdce.h header defines DceErrorInqText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).