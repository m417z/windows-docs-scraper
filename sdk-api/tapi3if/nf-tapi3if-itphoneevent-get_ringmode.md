# ITPhoneEvent::get_RingMode

## Description

The
**get_RingMode** method returns a long value specifying the ring mode to which the phone has transitioned. This information is available only when the
[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event) method returns PE_RINGMODE.

## Parameters

### `plRingMode` [out]

Ring mode.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)