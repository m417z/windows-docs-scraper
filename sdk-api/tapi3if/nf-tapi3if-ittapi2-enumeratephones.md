# ITTAPI2::EnumeratePhones

## Description

The
**EnumeratePhones** method enumerates the phone objects corresponding to the phone devices. If there are no phones available that can be used with the address, this method produces an empty enumeration and returns S_OK.

This method is intended for C/C++ applications. Visual Basic and scripting applications must use the
[get_Phones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi2-get_phones) method.

## Parameters

### `ppEnumPhone` [out]

Pointer to an
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone) interface returned by **ITTAPI2::EnumeratePhones**. The application must call **Release** on the
**IEnumPhone** interface to free resources associated with it.

## See also

[IEnumPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ienumphone)

[ITTAPI2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi2)