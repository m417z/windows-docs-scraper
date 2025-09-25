# IDispatch::GetTypeInfo

## Description

Retrieves the type information for an object, which can then be used to get the type information for an interface.

## Parameters

### `iTInfo` [in]

The type information to return. Pass 0 to retrieve type information for the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) implementation.

### `lcid` [in]

The locale identifier for the type information. An object may be able to return different type information for different languages. This is important for classes that support localized member names. For classes that do not support localized member names, this parameter can be ignored.

### `ppTInfo` [out]

The requested type information object.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **DISP_E_BADINDEX** | The *iTInfo* parameter was not 0. |

## See also

[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch)

[IWebBrowser2](https://learn.microsoft.com/windows/desktop/api/exdisp/nn-exdisp-iwebbrowser2)