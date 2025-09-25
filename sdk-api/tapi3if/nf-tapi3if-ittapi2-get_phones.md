# ITTAPI2::get_Phones

## Description

The
**get_Phones** method enumerates the phone objects corresponding to the phone devices. If there are no phones available that can be used with the address, this method produces an empty collection and returns S_OK.

This method is intended for Visual Basic and scripting applications. C/C++ applications will find the
[EnumeratePhones](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi2-enumeratephones) method more convenient.

## Parameters

### `pPhones` [out]

Pointer to a **VARIANT** containing an
[ITCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcollection) of
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface pointers.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

TAPI calls the **AddRef** method on the
[ITPhone](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itphone) interface returned by **ITTAPI2::get_Phones**. The application must call **Release** on the
**ITPhone** interface to free resources associated with it.

## See also

**IEnumPhone**

[ITTAPI2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi2)