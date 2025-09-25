# IUpdateServiceRegistration::get_IsPendingRegistrationWithAU

## Description

Gets a Boolean value that indicates whether the service will also be registered with Automatic Updates, when added. The authorization cabinet file (.cab) of the service determines whether the service can be added.

This property is read-only.

## Parameters

## Remarks

If the [RegistrationState](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-updateserviceregistrationstate) property is **usrsRegistrationPending**, registration with Automatic Updates is subject to the allowed settings that are specified in the authorization cabinet file (.cab) for the service. If the authorization cabinet file does not allow registration with Automatic Updates, the service will be registered with Windows Update Agent (WUA). However, the service will not be registered with Automatic Updates.

## See also

[IUpdateServiceRegistration](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateserviceregistration)