# INetFwAuthorizedApplications::Remove

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

The **Remove** method removes an application from the collection.

## Parameters

### `imageFileName` [in]

Application name to be removed.

## Return value

### C++

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

### VB

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |

## Remarks

The **imageFileName** parameter must be a fully qualified path and may contain environment variables.

If the application does not exist in the collection, the Remove method has no effect.

## See also

[INetFwAuthorizedApplications](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwauthorizedapplications)