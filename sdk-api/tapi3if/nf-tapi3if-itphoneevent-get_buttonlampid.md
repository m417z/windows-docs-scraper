# ITPhoneEvent::get_ButtonLampId

## Description

The
**get_ButtonLampId** method returns a long value indicating which button or lamp triggered the event. This information is available only when
[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event) returns PE_LAMPMODE or PE_BUTTON.

## Parameters

### `plButtonLampId` [out]

Button or lamp ID.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)