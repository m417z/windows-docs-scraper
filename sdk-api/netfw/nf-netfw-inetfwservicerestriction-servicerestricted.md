# INetFwServiceRestriction::ServiceRestricted

## Description

The **ServiceRestricted** method indicates whether service restriction rules are enabled to limit traffic to the resources specified by the firewall rules.

## Parameters

### `serviceName` [in]

Name of the service being queried concerning service restriction state.

### `appName` [in]

Name of the application being queried concerning service restriction state.

### `serviceRestricted` [out]

Indicates whether service restriction rules are in place to restrict the specified service. If true (**VARIANT_TRUE**), service is restricted. Otherwise, service is not restricted to the resources specified by firewall rules.

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

### VB

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |
| **E_OUTOFMEMORY** | The method was unable to allocate required memory. |
| **E_POINTER** | The method failed due to an invalid pointer. |

## See also

[INetFwServiceRestriction](https://learn.microsoft.com/windows/desktop/api/netfw/nn-netfw-inetfwservicerestriction)