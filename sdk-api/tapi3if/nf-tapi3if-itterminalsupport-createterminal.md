# ITTerminalSupport::CreateTerminal

## Description

The
**CreateTerminal** method creates and initializes a new
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) object based on the dynamic terminal class and media. The
[terminal class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class) is identified by a GUID. The GUID must be converted to a string using
[StringFromIID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromiid) to pass to this method.

## Parameters

### `pTerminalClass` [in]

Pointer to **BSTR** containing the
[terminal class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class) (GUID) for the new terminal object.

### `lMediaType` [in]

Pointer to the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) for the new terminal object.

### `Direction` [in]

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor of the terminal direction.

### `ppTerminal` [out]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) object created.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *pTerminalClass* or *lMediaType* parameter is not valid. |
| **E_POINTER** | The *ppTerminal* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to create the [ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) object. |
| **E_MEDIATYPE** | The *lMediaType* parameter is invalid. |
| **TAPI_E_NOTSUPPORTED** | Dynamic terminal creation is not supported. |

## Remarks

The application must use
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to allocate memory for the *pTerminalClass* parameter and use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory when the variable is no longer needed.

Once a terminal is created, it can be selected onto only one call.

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
**ITTerminal** interface returned by **ITTerminalSupport::CreateTerminal**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITTerminal** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITTerminalSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport)

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)

[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants)

[terminal class](https://learn.microsoft.com/windows/desktop/Tapi/terminal-class)