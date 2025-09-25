# ITTerminalSupport::GetDefaultStaticTerminal

## Description

The
**GetDefaultStaticTerminal** method gets the default static terminal for the
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) specified.

## Parameters

### `lMediaType` [in]

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) of the required terminal.

### `Direction` [in]

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor of the terminal direction.

### `ppTerminal` [out]

Pointer to the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface. **NULL** if no terminal is available.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **S_FALSE** | No terminal is available. **ppTerminal* will be returned as **NULL**. |
| **E_FAIL** | Unspecified error. |
| **E_POINTER** | The *lMediaType* parameter is not a valid pointer. |
| **E_MEDIATYPE** | The *lMediaType* parameter is not a valid media type. |
| **E_OUTOFMEMORY** | Insufficient memory exists to create the Terminal object. |

## Remarks

This method does not return dynamic terminals. For example, having a media type of TAPIMEDIATYPE_VIDEO and a terminal direction of TD_RENDER defines a dynamic terminal; this method will fail with those parameters.

The default static terminal returned by this method is one of the static terminals returned by
[ITTerminalSupport::EnumerateStaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-enumeratestaticterminals) or
[ITTerminalSupport::get_StaticTerminals](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-get_staticterminals). Usually, the default terminal is the one selected as "preferred device" in Control Panel's "Sounds and Multimedia Properties" applet.

TAPI calls the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by **ITTerminalSupport::GetDefaultStaticTerminal**. The application must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the
**ITTerminal** interface to free resources associated with it.

## See also

[Address Object](https://learn.microsoft.com/windows/desktop/Tapi/address-object)

[ITTerminalSupport](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminalsupport)

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants)

[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction)

[Terminal Object](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object)

[Terminal Object Interfaces](https://learn.microsoft.com/windows/desktop/Tapi/terminal-object-interfaces)