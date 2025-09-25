# TdhOpenDecodingHandle function

## Description

Opens a decoding handle.

## Parameters

### `Handle` [out]

Type: **PTDH_HANDLE**

A valid decoding handle.

## Return value

Type: **ULONG**

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameter is incorrect. This error is returned if the *Handle* parameter is **NULL**. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory allocations failed. |

## Remarks

Call [TdhCloseDecodingHandle](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhclosedecodinghandle) to free the returned handle.

## See also
[TdhCloseDecodingHandle](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhclosedecodinghandle)