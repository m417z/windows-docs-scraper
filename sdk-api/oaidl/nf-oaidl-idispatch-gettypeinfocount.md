# IDispatch::GetTypeInfoCount

## Description

Retrieves the number of type information interfaces that an object provides (either 0 or 1).

## Parameters

### `pctinfo` [out]

The number of type information interfaces provided by the object. If the object provides type information, this number is 1; otherwise the number is 0.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_NOTIMPL** | Failure. |

## Remarks

The method may return zero, which indicates that the object does not provide any type information. In this case, the object may still be programmable through **IDispatch** or a VTBL, but does not provide run-time type information for browsers, compilers, or other programming tools that access type information. This can be useful for hiding an object from browsers.

#### Examples

This code from the Lines sample file Lines.cpp implements the **GetTypeInfoCount** member function for the **CLines** class (ActiveX or OLE object).

```cpp
STDMETHODIMP
CLines::GetTypeInfoCount(UINT * pctinfo)
{
   if (pctinfo == NULL) {
      return E_INVALIDARG;
}
   *pctinfo = 1;
   return NOERROR;
}
```

## See also

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)