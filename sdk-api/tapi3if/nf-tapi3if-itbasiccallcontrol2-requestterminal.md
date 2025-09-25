# ITBasicCallControl2::RequestTerminal

## Description

The
**RequestTerminal** method gets a suitable terminal, given the class, media, and direction required.

## Parameters

### `bstrTerminalClassGUID` [in]

The terminal class required for the call.

### `lMediaType` [in]

Bitwise ORed list of
[media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) required for the call.

### `Direction` [in]

The
[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor for the terminal.

### `ppTerminal` [out]

Pointer to
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **AddRef** method is automatically called on the
[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal) interface returned by this method. The application must call the **Release** method on the
**ITTerminal** interface to free resources associated with it.

## See also

[ITBasicCallControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itbasiccallcontrol2)

[ITTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itterminal)