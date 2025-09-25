# SERVICE_LAUNCH_PROTECTED_INFO structure

## Description

Indicates a service protection type.

## Members

### `dwLaunchProtected`

The protection type of the service. This member can be one of the following values:

#### SERVICE_LAUNCH_PROTECTED_NONE (0)

#### SERVICE_LAUNCH_PROTECTED_WINDOWS (1)

#### SERVICE_LAUNCH_PROTECTED_WINDOWS_LIGHT (2)

#### SERVICE_LAUNCH_PROTECTED_ANTIMALWARE_LIGHT (3)

## Remarks

This structure is used by the [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a) function to specify the protection type of the service, and it is used with [QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a) to retrieve service configuration information for protected services. In order to apply any protection type to a service, the service must be signed with an appropriate certificate.

The **SERVICE_LAUNCH_PROTECTED_WINDOWS** and **SERVICE_LAUNCH_PROTECTED_WINDOWS_LIGHT** protection types are reserved for internal Windows use only.

The **SERVICE_LAUNCH_PROTECTED_ANTIMALWARE_LIGHT** protection type can be used by the anti-malware vendors to launch their anti-malware service as protected. See [Protecting Anti-Malware Services](https://learn.microsoft.com/windows/desktop/Services/protecting-anti-malware-services-) for more info.

Once the service is launched as protected, other unprotected processes will not be able to call the following APIs on the protected service.

* [ChangeServiceConfig](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfiga)
* [ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)
* [ControlService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlservice)
* [ControlServiceEx](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-controlserviceexa)
* [DeleteService](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-deleteservice)
* [SetServiceObjectSecurity](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-setserviceobjectsecurity)