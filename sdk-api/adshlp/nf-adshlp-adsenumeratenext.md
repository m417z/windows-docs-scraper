# ADsEnumerateNext function

## Description

The **ADsEnumerateNext** function enumerates through a specified number of elements from the current cursor position of the enumerator. When the operation succeeds, the function returns the enumerated set of elements in a variant array. The number of returned elements can be smaller than the specified number.

## Parameters

### `pEnumVariant` [in]

Type: **IEnumVARIANT***

Pointer to the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface on the enumerator object.

### `cElements` [in]

Type: **ULONG**

Number of elements requested.

### `pvar` [out]

Type: **VARIANT***

Pointer to the array of elements retrieved.

### `pcElementsFetched` [out]

Type: **ULONG***

Actual number of elements retrieved, which can be smaller than the number of elements requested.

## Return value

Type: **HRESULT**

This method supports the standard return values.

For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

The general process to enumerate objects in a container involves the following:

First, create an enumerator object on that container.

Second, retrieve the [IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant) interface pointer.

Third, call the **ADsEnumerateNext** function to return an enumerated set of elements from the enumerator object.

Fourth, call the [ADSFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator) function to free the enumerator object.

For more information and a code example, see the [ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator) topic.

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[ADSI Functions](https://learn.microsoft.com/windows/desktop/ADSI/adsi-functions)

[ADsBuildEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsbuildenumerator)

[ADsFreeEnumerator](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-adsfreeenumerator)

[FreeADsMem](https://learn.microsoft.com/windows/desktop/api/adshlp/nf-adshlp-freeadsmem)

[IEnumVARIANT](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ienumvariant)