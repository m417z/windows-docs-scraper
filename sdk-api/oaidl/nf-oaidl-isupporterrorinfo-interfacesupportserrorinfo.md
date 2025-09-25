# ISupportErrorInfo::InterfaceSupportsErrorInfo

## Description

Indicates whether an interface supports the [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) interface.

## Parameters

### `riid` [in]

An interface identifier (IID).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The interface supports [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo). |
| **S_FALSE** | The interface does not support [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo). |

## Remarks

Objects that support the [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) interface must also implement this interface.

Programs that receive an error return value should call **QueryInterface** to get a pointer to the [ISupportErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo) interface, and then call **InterfaceSupportsErrorInfo** with the *riid* of the interface that returned the return value. If **InterfaceSupportsErrorInfo** returns S_FALSE, then the error object does not represent an error returned from the caller, but from somewhere else. In this case, the error object can be considered incorrect and should be discarded.

If [ISupportErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo) returns S_OK, use the [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo) function to get a pointer to the error object.

For an example that demonstrates implementing **InterfaceSupportsErrorInfo**, see the ErrorInfo.cpp file in the COM Fundamentals Lines sample.

## See also

[ISupportErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-isupporterrorinfo)