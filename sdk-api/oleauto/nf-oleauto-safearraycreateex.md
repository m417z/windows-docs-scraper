# SafeArrayCreateEx function

## Description

Creates and returns a safe array descriptor from the specified VARTYPE, number of dimensions and bounds.

## Parameters

### `vt` [in]

The base type or the VARTYPE of each element of the array. The FADF_RECORD flag can be set for a variant type VT_RECORD, The FADF_HAVEIID flag can be set for VT_DISPATCH or VT_UNKNOWN, and FADF_HAVEVARTYPE can be set for all other VARTYPEs.

### `cDims` [in]

The number of dimensions in the array.

### `rgsabound` [in]

A vector of bounds (one for each dimension) to allocate for the array.

### `pvExtra` [in]

the type information of the user-defined type, if you are creating a safe array of user-defined types. If the vt parameter is VT_RECORD, then *pvExtra* will be a pointer to an [IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo) describing the record. If the *vt* parameter is VT_DISPATCH or VT_UNKNOWN, then *pvExtra* will contain a pointer to a GUID representing the type of interface being passed to the array.

## Return value

A safe array descriptor, or null if the array could not be created.

## Remarks

If the VARTYPE is VT_RECORD then [SafeArraySetRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraysetrecordinfo) is called. If the VARTYPE is VT_DISPATCH or VT_UNKNOWN then the elements of the array must contain interfaces of the same type. Part of the process of marshaling this array to other processes does include generating the proxy/stub code of the IID pointed to by the *pvExtra* parameter. To actually pass heterogeneous interfaces one will need to specify either IID_IUnknown or IID_IDispatch in *pvExtra* and provide some other means for the caller to identify how to query for the actual interface.

#### Examples

The following example describes how a safe array of user-defined types is stored into a variant of type VT_RECORD.

```cpp
SAFEARRAYBOUND * sab;
sab.cElements = 2;
sab.lLbound = 0;
hresult hr;

SAFEARRAY Sa;
Sa = SafeArrayCreateEx(VT_RECORD, 1, &sab, pRecInfo);
if (Sa == NULL)
   return E_OUTOFMEMORY;

PVOID pvData;
hr = SafeArrayAccessData(Sa, &pvData);
if (FAILED(hr)) {
   SafeArrayDestroy(Sa);
   return hr;
}

TEST * pTest;
pTest = (TEST *)pvData;
pTest[0] = a;
pTest[1] = b;
hr = SafeArrayUnaccessData(Sa);
if (FAILED(hr)) {
   SafeArrayDestroy(Sa);
   return hr;
}

VariantInit(&variant);
V_VT(&variant) = VT_ARRAY|VT_RECORD;
V_ARRAY(&variant) = Sa;
```