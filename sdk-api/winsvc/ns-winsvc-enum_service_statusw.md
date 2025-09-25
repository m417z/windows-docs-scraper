# ENUM_SERVICE_STATUSW structure

## Description

Contains the name of a service in a service control manager database and information about that service. It is used by the
[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa) and
[EnumServicesStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusa) functions.

## Members

### `lpServiceName`

The name of a service in the service control manager database. The maximum string length is 256 characters. The service control manager database preserves the case of the characters, but service name comparisons are always case insensitive. A slash (/), backslash (\\), comma, and space are invalid service name characters.

### `lpDisplayName`

A display name that can be used by service control programs, such as Services in Control Panel, to identify the service. This string has a maximum length of 256 characters. The name is case-preserved in the service control manager. Display name comparisons are always case-insensitive.

### `ServiceStatus`

A
[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status) structure that contains status information for the **lpServiceName** service.

## See also

[EnumDependentServices](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumdependentservicesa)

[EnumServicesStatus](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-enumservicesstatusa)

[SERVICE_STATUS](https://learn.microsoft.com/windows/desktop/api/winsvc/ns-winsvc-service_status)

## Remarks

> [!NOTE]
> The winsvc.h header defines ENUM_SERVICE_STATUS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).