# ITTerminalManager::CreateDynamicTerminal

## Description

The
**CreateDynamicTerminal** method creates a dynamic terminal of a specified terminal class, media type, and direction.

## Parameters

### `pOuterUnknown` [in]

If MSP will aggregate the terminal object, set to IUnknown interface pointer for MSP object. Usually this is set to **NULL**.

### `iidTerminalClass` [in]

GUID identifying class of terminal to be created.

### `dwMediaType` [in]

Descriptor of
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) for stream.

### `Direction` [in]

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor of the media stream direction for terminal.

### `htAddress` [in]

MSP handle.

### `ppTerminal` [out]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface for new terminal.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *fMessageWaiting* parameter is not valid. |
| **E_POINTER** | The *ppAddress* parameter is not a valid pointer. |

## Remarks

When choosing a value for *pTerminalClass*, the only terminal class GUIDs that can be used are those that correspond to terminals that are "dynamically" created. For example, from all terminal classes currently defined by TAPI3, only the following can be used with CreateTerminal: CLSID_MediaStreamTerminal and CLSID_VideoWindowTerm.

In addition, only those dynamic terminal classes that are supported on this address can be used. The application can discover these values by using
[ITTerminalSupport::EnumerateDynamicTerminalClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratedynamicterminalclasses) or
[ITTerminalSupport::get_DynamicTerminalClasses](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_dynamicterminalclasses).

The application must obtain the *pTerminalClass* **BSTR** in two steps: call **StringFromIID** to convert the GUID to an **LPOLESTR**, then call
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) to convert the **LPOLESTR** to a **BSTR**.

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *pTerminalClass* parameter.

## See also

[ITTerminalManager](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalmanager)

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction)

[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants)