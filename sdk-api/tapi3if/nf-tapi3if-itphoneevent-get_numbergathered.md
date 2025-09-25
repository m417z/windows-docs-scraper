# ITPhoneEvent::get_NumberGathered

## Description

The
**get_NumberGathered** method returns a **BSTR** value specifying the phone number that was gathered. This information is available only when the
[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event) method returns PE_NUMBERGATHERED.

## Parameters

### `ppNumber` [out]

Phone number that was gathered. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) and should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhoneEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphoneevent)

[ITPhoneEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphoneevent-get_event)