# ITfKeystrokeMgr::SimulatePreservedKey

## Description

Simulates the execution of a preserved key sequence.

## Parameters

### `pic` [in]

Pointer to the application context. This value was returned by a previous call to [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext).

### `rguid` [in]

Contains the command GUID of the preserved key.

### `pfEaten` [out]

Pointer to a BOOL that indicates if the key event was handled. If this value receives **TRUE**, the key event was handled. If this value is **FALSE**, the key event was not handled.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The preserved key cannot be simulated. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_FAIL** | An unspecified error occurred. |

## See also

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfKeystrokeMgr](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfkeystrokemgr)