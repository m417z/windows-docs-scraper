# ITTerminalManager2::GetPluggableTerminalClasses

## Description

The
**GetPluggableTerminalClasses** method lists the terminal classes for all pluggable terminals registered under a terminal superclass.

## Parameters

### `iidSuperclass` [in]

A **BSTR** that represents the CLSID for the parent superclass.

### `dwMediaTypes` [in]

Bitwise ORed list of
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants). The method returns only terminals that support these media types.

### `pdwNumClasses` [in, out]

If the *pTerminalClasses* parameter is **NULL**, this parameter returns the total number of terminals registered under the terminal superclass specified by the *iidSuperclass* parameter.

If *pTerminalClasses* is not **NULL**, and the method completes successfully, this parameter returns a count of the number of terminal IIDs returned in the *pTerminalClasses* buffer.

### `pTerminalClasses` [out]

Pointer to the buffer to receive the terminals IIDs. This parameter can also be **NULL**. For more information, see the description of the *pdwNumClasses* parameter.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pTerminalClasses* parameter doesn't represent an IID or list of IIDs. |
| **E_FAIL** | The method failed. |
| **E_POINTER** | The *pTerminalClasses* parameter is not a valid pointer. |

## See also

[ITTerminalManager2](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalmanager2)