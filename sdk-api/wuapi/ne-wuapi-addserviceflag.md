# AddServiceFlag enumeration

## Description

Defines the possible ways in which the [IUpdateServiceManager2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager2) interface can process service registration requests.

## Constants

### `asfAllowPendingRegistration:0x1`

Allows the update agent to process the service registration at a later time, when it next performs an online scan for updates.

### `asfAllowOnlineRegistration:0x2`

Allows the update agent to process the service registration immediately if network connectivity is available.

### `asfRegisterServiceWithAU:0x4`

Registers the service with Automatic Updates when the service is added.

## Remarks

For info about how [IUpdateServiceManager2::AddService2](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager2-addservice2) behaves when you specify different combinations of **AddServiceFlag** values in the *flags* parameter, see the Remarks section of **IUpdateServiceManager2::AddService2**.

## See also

[IUpdateServiceManager2::AddService2](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager2-addservice2)