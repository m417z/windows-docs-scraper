# INetFwServiceRestriction::RestrictService

## Description

The **RestrictService** method turns service restriction on or off for a given service.

## Parameters

### `serviceName` [in]

Name of the service for which service restriction is being turned on or off.

### `appName` [in]

Name of the application for which service restriction is being turned on or off.

### `restrictService` [in]

Indicates whether service restriction is being turned on or off. If this value is true (**VARIANT_TRUE**), the service will be restricted when sending or receiving network traffic. The Windows Service Hardening rules collection can contain rules which can allow this service specific inbound or outbound network access per specific requirements. If false (**VARIANT_FALSE**), the service is not restricted by Windows Service Hardening.

### `serviceSidRestricted` [in]

Indicates the type of service SID for the specified service. If this value is true (**VARIANT_TRUE**), the service SID will be restricted. Otherwise, it will be unrestricted.

## Return value

### C++

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |

### VB

If the method succeeds the return value is S_OK.

If the method fails, the return value is one of the following error codes.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | The operation was aborted due to permissions issues. |
| **E_INVALIDARG** | The method failed due to an invalid parameter. |

## Remarks

When adding rules, note that there may be a small time lag before the newly-added rule is applied.

## See also

[INetFwServiceRestriction](https://learn.microsoft.com/windows/desktop/api/netfw/nn-netfw-inetfwservicerestriction)