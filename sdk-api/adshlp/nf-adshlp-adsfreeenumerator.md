# ADsFreeEnumerator function

## Description

The **ADsFreeEnumerator** function frees an enumerator object created with the [ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator) function.

## Parameters

### `pEnumVariant` [in]

Type: **IEnumVARIANT***

Pointer to the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface on the enumerator object to be freed.

## Return value

Type: **HRESULT**

This method supports standard return values, as well as the following.

## Remarks

The general process for enumerating objects in a container is as follows.

First, create an enumerator object on that container.

Second, retrieve the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface pointer.

Third, call the [ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext) function to return an enumerated set of elements from the enumerator object.

Fourth, call the **ADSFreeEnumerator** function to free the enumerator object.

For more information and a code example, see [ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator).

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator)

[ADsEnumerateNext](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsenumeratenext)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)