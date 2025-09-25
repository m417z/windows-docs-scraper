# ITypeLib::GetTypeInfo

## Description

Retrieves the specified type description in the library.

## Parameters

### `index` [in]

The index of the interface to be returned.

### `ppTInfo` [out]

If successful, returns a pointer to the pointer to the [ITypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypeinfo) interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **TYPE_E_ELEMENTNOTFOUND** | The *index* parameter is outside the range of to [GetTypeInfoCount](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypelib-gettypeinfocount) - 1. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## Remarks

For dual interfaces, **GetTypeInfo** returns only the TKIND_DISPATCH type information. To get the TKIND_INTERFACE type information, [GetRefTypeOfImplType](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getreftypeofimpltype) can be called on the TKIND_DISPATCH type information, passing an index of –1. Then, the returned type information handle can be passed to [GetRefTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-itypeinfo-getreftypeinfo).

#### Examples

The following example gets the TKIND_INTERFACE type information for a dual interface.

```cpp
HRESULT hr;
hr = ptlib->GetTypeInfo((unsigned int) dwIndex, &ptypeinfoDisp);
if (FAILED(hr)) {
   //free resources
   return hr;
}
hr = ptypeinfoDisp->GetRefTypeOfImplType(-1, &phreftype);
if (FAILED(hr)) {
   //free resources
   return hr;

hr = ptypeinfoDisp->GetRefTypeInfo(phreftype, &ptypeinfoInt);
if (FAILED(hr)) {
   //free resources
   return hr;

//
```

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)