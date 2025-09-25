# IWbemHiPerfEnum::GetObjects

## Description

The
**IWbemHiPerfEnum::GetObjects** method retrieves objects currently residing in the enumerator.

## Parameters

### `lFlags` [in]

Integer that contains the flags.

### `uNumObjects` [in]

Size of the array passed to this method in the *apObj* parameter.

### `apObj` [out]

Pointer that holds the reference to an array of
[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess) objects, which contains the returned objects. The array must be big enough to hold all objects in the enumerator.

### `puReturned` [out]

Pointer to a **ULONG** used to return the number of objects placed in the array.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

The array must be large enough to hold all objects, or *puReturned* is filled with the number of returned objects, and **WBEM_E_BUFFER_TOO_SMALL** is returned.

## See also

[IWbemHiPerfEnum](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)