# INetFwServices::Item

## Description

[The Windows Firewall API is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. For Windows Vista and later, use of the [Windows Firewall with Advanced Security](https://learn.microsoft.com/previous-versions/windows/desktop/ics/windows-firewall-advanced-security-start-page) API is recommended.]

Returns the specified service if it is in the collection.

## Parameters

### `svcType` [in]

|  |  |
| --- | --- |
| **C++** | Type of service to fetch. |
| **VB** | Type of service to fetch. See [NET_FW_SERVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_service_type) |

### `service` [out]

|  |  |
| --- | --- |
| **C++** | Reference to the returned **INetFwService** object. |
| **VB** | Reference to the returned [INetFwService](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwservice) object. |

## Return value

### C++

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The method failed because the requested item does not exist. |

### VB

If the method succeeds, the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)** | The method failed because the requested item does not exist. |

## See also

[INetFwService](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwservice)

[INetFwServices](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nn-netfw-inetfwservices)

[NET_FW_SERVICE_TYPE](https://learn.microsoft.com/windows/desktop/api/icftypes/ne-icftypes-net_fw_service_type)