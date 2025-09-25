# ITPhone::get_PhoneCapsString

## Description

The
**get_PhoneCapsString** method gets a string capability/information about the phone, based on the
[PHONECAPS_STRING](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_string) enum passed in. The application does not have to call
[ITPhone::Open](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itphone-open) before executing this method.

## Parameters

### `pcsCap` [in]

The
[PHONECAPS_STRING](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-phonecaps_string) descriptor for the phone capability.

### `ppCapability` [out]

Capability value. The **BSTR** is allocated using
[SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). The **BSTR** argument should be deallocated by the client.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone)

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)