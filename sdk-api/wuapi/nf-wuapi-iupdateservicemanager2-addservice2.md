# IUpdateServiceManager2::AddService2

## Description

Registers a service with Windows Update Agent (WUA) without requiring an authorization cabinet file (.cab). This method also returns a pointer to an [IUpdateServiceRegistration](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicecollection) interface.

## Parameters

### `serviceID` [in]

An identifier for the service to be registered.

### `flags` [in]

A combination of [AddServiceFlag](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-addserviceflag) values that are combined by using a bitwise OR operation. The resulting value specifies options for service registration. For more info, see Remarks.

### `authorizationCabPath` [in]

The path of the Microsoft signed local cabinet file (.cab) that has the information that is required for a service registration. If empty, the update agent searches for the authorization cabinet file (.cab) during service registration when a network connection is available.

### `retval` [out]

A pointer to an [IUpdateServiceRegistration](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateserviceregistration) interface that represents an added service.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

This method can also return the following error codes.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | A parameter value is invalid. |
| **E_ACCESSDENIED** | This method cannot be called from a remote computer if the *authorizationCabPath* parameter is set to a null string. |
| **WU_E_DS_SERVICEEXPIRED** | The authorization cabinet file (.cab) has expired. |
| **WU_E_DS_INVALIDOPERATION** | The state of Automatic Updates could not be changed. |

## Remarks

This method may return [networking error codes](https://learn.microsoft.com/windows/desktop/Wua_Sdk/wua-networking-error-codes-) when the **asfAllowOnlineRegistration** flag is specified.

The *authorizationCabPath* parameter is optional for this method. If the *authorizationCabPath* parameter is not specified, it will be retrieved from the Windows Update server.

This method returns **E_INVALIDARG** if the **asfAllowOnlineRegistration** or **asfAllowPendingRegistration** flags are specified and if the value of the *authorizationCabPath* parameter is not an empty string.

This method returns **WU_E_DS_INVALIDOPERATION** if the requested change in the state of Automatic Updates is contrary to the specifications in the authorization cabinet file (.cab) when the **asfRegisterServiceWithAU** flag is specified. An error is returned by the [WinVerifyTrust](https://learn.microsoft.com/windows/desktop/api/wintrust/nf-wintrust-winverifytrust) function if the authorization cabinet file has not been signed.

The update agent and **AddService2** behave in the following ways depending on the [AddServiceFlag](https://learn.microsoft.com/windows/desktop/api/wuapi/ne-wuapi-addserviceflag) values that you specify in the *flags* parameter:

* If you specify **asfAllowOnlineRegistration** without **asfAllowPendingRegistration**, the update agent immediately attempts to go online to register the service. **AddService2** returns an HRESULT value that reflects the success or failure of the registration. If the registration fails, the update agent makes no future attempts to register the service.
* If you specify **asfAllowPendingRegistration** without **asfAllowOnlineRegistration**, the update agent doesn't register the service immediately. **AddService2** returns S_OK to indicate that the update agent will attempt to register the service at a later time, which doesn't guarantee that the registration will eventually succeed.
* If you specify **asfAllowPendingRegistration** and **asfAllowOnlineRegistration** together, the update agent immediately attempts to go online to register the service. **AddService2** returns S_OK if the registration succeeds. **AddService2** returns a failure HRESULT value if the registration fails, but the update agent still attempts to register the service at a later time.
* If you specify **asfAllowPendingRegistration**, **asfAllowOnlineRegistration**, or both, also specify **NULL** for the *authorizationCabPath* parameter.
* If you specify neither **asfAllowPendingRegistration** nor **asfAllowOnlineRegistration** (in other words, if *flags* is either zero or **asfRegisterServiceWithAU**), you must specify a non-**NULL** path in the *authorizationCabPath* parameter. In this mode, **AddService2** processes the cabinet file (.cab) and registers the service in the same way as [IUpdateServiceManager::AddService](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iupdateservicemanager-addservice).
* If you specify **asfRegisterServiceWithAU**, the change to the default Automatic Updates service doesn't occur (and isn't reflected in the Windows Update user interface) until the service registration succeeds. This means that if the registration succeeds immediately (because you specified **asfAllowPendingRegistration** or supplied a cabinet file (.cab)), the Automatic Updates service change also occurs immediately. If the registration doesn't succeed until later (because you specified **asfAllowPendingRegistration**), the Automatic Updates service change doesn't occur unless the pending service registration eventually succeeds.

## See also

[IUpdateServiceManager2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager2)