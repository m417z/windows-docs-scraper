# INetFwAuthorizedApplications::Item

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

The **Item** method returns the specified application if it is in the collection.

## Parameters

### `imageFileName` [in]

Application to retrieve.

### `app` [out]

Reference to the returned [INetFwAuthorizedApplication](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplication) object.

## Return value

### C++

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The requested item does not exist. |

### VB

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The requested item does not exist. |

## See also

[INetFwAuthorizedApplication](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplication)

[INetFwAuthorizedApplications](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplications)