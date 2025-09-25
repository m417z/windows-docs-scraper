# ITTerminalManager::GetDynamicTerminalClasses

## Description

The
**GetDynamicTerminalClasses** method gets a list of terminal classes for a set of media types.

## Parameters

### `dwMediaTypes` [in]

Pointer to
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants).

### `pdwNumClasses` [in, out]

Number of terminal classes returned.

### `pTerminalClasses` [out]

Pointer to list of
[terminal classes](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pdwNumClasses* or the *pTerminalClasses* parameter is not a valid pointer. |
| **TAPI_E_NOTENOUGHMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_NOTSUPPORTED** | Dynamic terminals not supported on this address. |

## See also

[ITTerminalManager](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalmanager)