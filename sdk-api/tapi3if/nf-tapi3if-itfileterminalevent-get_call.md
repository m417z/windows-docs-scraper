# ITFileTerminalEvent::get_Call

## Description

The
**get_Call** method gets a pointer to the call information interface for the call on which the event has occurred.

## Parameters

### `ppCall` [out]

Pointer to the
[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a terminal must generate an event, it requires a selected track in order to pass the event to an MSP which will then pass it to the application through TAPI. The first track that accepts the task of sending the event will be used. If the terminal has more than one track and the tracks are selected onto streams that belong to different calls, the call object pointer eventually returned could be for any of those calls.

## See also

[ITCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallinfo)

[ITFileTerminalEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itfileterminalevent)