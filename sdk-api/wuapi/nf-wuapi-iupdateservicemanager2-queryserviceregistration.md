# IUpdateServiceManager2::QueryServiceRegistration

## Description

Returns a pointer to an [IUpdateServiceRegistration](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateserviceregistration) interface.

## Parameters

### `serviceID` [in]

An identifier for the service to be registered.

### `retval` [out]

A pointer to an [IUpdateServiceRegistration](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateserviceregistration) interface that represents an added service.

## Return value

Returns **S_OK** if successful. Otherwise, returns a COM or Windows error code.

## See also

[IUpdateServiceManager2](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdateservicemanager2)