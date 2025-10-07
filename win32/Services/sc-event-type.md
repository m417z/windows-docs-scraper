# SC\_EVENT\_TYPE enumeration

Indicates a type of service status change for monitoring and reporting.

## Constants

**SC\_EVENT\_DATABASE\_CHANGE**

A service has been added or deleted. The *hService* parameter of the [**SubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/subscribeservicechangenotifications) function must be a handle to the SCM.

**SC\_EVENT\_PROPERTY\_CHANGE**

One or more of service properties have been updated. The *hService* parameter of the [**SubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/subscribeservicechangenotifications) function must be a handle to the service.

**SC\_EVENT\_STATUS\_CHANGE**

The status of a service has changed. The *hService* parameter of the [**SubscribeServiceChangeNotifications**](https://learn.microsoft.com/windows/win32/services/subscribeservicechangenotifications) function must be a handle to the service.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Header<br> | Winsvcp.h |

