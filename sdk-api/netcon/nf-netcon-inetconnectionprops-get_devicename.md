# INetConnectionProps::get_DeviceName

## Description

[Internet Connection Firewall may be altered or unavailable in subsequent versions. Instead, use the [Windows Firewall API](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-start-page).]

The
**get_DeviceName** method retrieves the name of the device associated with the connection.

## Parameters

### `pbstrDeviceName` [out]

Pointer to a
[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr) variable that, on successful return, receives the name of the device associated with the connection.

## Return value

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ABORT** | The operation was aborted. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_NOINTERFACE** | A specified interface is not supported. |
| **E_NOTIMPL** | A specified method is not implemented. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |
| **E_UNEXPECTED** | The method failed for unknown reasons. |

## See also

[INetConnectionProps](https://learn.microsoft.com/previous-versions/windows/desktop/api/netcon/nn-netcon-inetconnectionprops)