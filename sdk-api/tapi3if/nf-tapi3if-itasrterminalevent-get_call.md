# ITASRTerminalEvent::get_Call

## Description

The
**get_Call** method returns a pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface for the call object involved in the terminal event.

## Parameters

### `ppCall` [out]

Pointer to
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an error value.

## See also

[ITASRTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itasrterminalevent)

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)