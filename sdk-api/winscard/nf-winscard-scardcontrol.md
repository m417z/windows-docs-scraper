# SCardControl function

## Description

The **SCardControl** function gives you direct control of the [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). You can call it any time after a successful call to [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) and before a successful call to [SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect). The effect on the [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the reader depends on the control code.

## Parameters

### `hCard` [in]

Reference value returned from
[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta).

### `dwControlCode` [in]

Control code for the operation. This value identifies the specific operation to be performed.

### `lpInBuffer` [in]

Pointer to a buffer that contains the data required to perform the operation. This parameter can be **NULL** if the *dwControlCode* parameter specifies an operation that does not require input data.

### `cbInBufferSize` [in]

Size, in bytes, of the buffer pointed to by *lpInBuffer*.

### `lpOutBuffer` [out]

Pointer to a buffer that receives the operation's output data. This parameter can be **NULL** if the *dwControlCode* parameter specifies an operation that does not produce output data.

### `cbOutBufferSize` [in]

Size, in bytes, of the buffer pointed to by *lpOutBuffer*.

### `lpBytesReturned` [out]

Pointer to a **DWORD** that receives the size, in bytes, of the data stored into the buffer pointed to by *lpOutBuffer*.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The **SCardControl** function is a direct card access function. For more information on other direct access functions, see
[Direct Card Access Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/direct-card-access-functions).

#### Examples

The following example issues a control code. The example assumes that hCardHandle is a valid handle received from a previous call to [SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta) and that dwControlCode is a variable of type **DWORD** previously initialized to a valid control code. This particular control code requires no input data and expects no output data.

```cpp

lReturn = SCardControl( hCardHandle,
                        dwControlCode,
                        NULL,
                        0,
                        NULL,
                        0,
                        0 );
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardControl\n");

```

## See also

[SCardConnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardconnecta)

[SCardDisconnect](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scarddisconnect)