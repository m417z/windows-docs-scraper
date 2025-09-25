# IADsExtension::PrivateGetIDsOfNames

## Description

The **IADsExtension::PrivateGetIDsOfNames** method is called by the aggregator, ADSI, after ADSI determines that the extension is used to support a dual or dispatch interface. The method can use the type data to get DISPID using [IDispatch::GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames).

## Parameters

### `riid`

Reserved for future use. It must be IID_NULL.

### `rgszNames`

Passed-in array of names to be mapped.

### `cNames`

Count of the names to be mapped.

### `lcid`

The locale context in which to interpret the names.

### `rgDispid`

Caller-allocated array, each element of which contains an identifier that corresponds to one of the names passed in the *rgszNames* array. The first element represents the member name. The subsequent elements represent each of the member's parameters.

## Return value

The return values are the same as those of the standard [IDispatch::GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames) method. For more information about other return values, see [ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes).

## Remarks

All the parameters have the same meaning as the corresponding ones in the standard [IDispatch::GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames)(). The extension component returns a unique identifier (*rgDispID*) for each method or property defined in the supported dual interfaces. The uniqueness is enforced within the extension component. The ADSI provider must ensure the uniqueness of the DISPIDs of all extension objects and the aggregator (ADSI) itself. The *rgDispID* parameter must be between 1 and 16777215 (2^24-1), or -1 (DISPID_UNKNOWN).

#### Examples

The following C/C++ code example shows a generic implementation of this method.

```cpp
STDMETHOD(PrivateGetIDsOfNames)(REFIID riid, OLECHAR ** rgszNames, unsigned int cNames, LCID lcid, DISPID  * rgdispid)
{
  if (rgdispid == NULL)
  {
     return E_POINTER;
  }
  return  DispGetIDsOfNames(m_pTypeInfo, rgszNames, cNames, rgdispid);
}
```

## See also

[ADSI Error Codes](https://learn.microsoft.com/windows/desktop/ADSI/adsi-error-codes)

[IADsExtension](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsextension)

[IADsExtension::PrivateInvoke](https://learn.microsoft.com/windows/desktop/api/iads/nf-iads-iadsextension-privateinvoke)

[IDispatch::GetIDsOfNames](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-getidsofnames)