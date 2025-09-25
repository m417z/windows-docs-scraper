# ITTAPI::RegisterCallNotifications

## Description

The
**RegisterCallNotifications** method sets which new call notifications an application will receive. The application must call the method for each address, indicating media type or types it can handle, and specifying the privileges it requests.

An application that will make only outgoing calls does not need to call this method.

The
[ITTAPIEventNotification](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapieventnotification) outgoing interface must be registered prior to calling this method.

If both owner and monitor privileges are needed for an address, this method should be called only once, with both *fMonitor* and *fOwner* set to **TRUE**.

## Parameters

### `pAddress` [in]

Pointer to
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface.

### `fMonitor` [in]

Boolean value indicating whether the application will monitor calls. VARIANT_TRUE indicates that the application will monitor calls; VARIANT_FALSE that it will not.

### `fOwner` [in]

Boolean value indicating whether the application will own incoming calls. VARIANT_TRUE indicates that the application will own incoming calls; VARIANT_FALSE indicates that it will not.

### `lMediaTypes` [in]

[Media types](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) that can be handled by the application.

### `lCallbackInstance` [in]

Callback instance to be used by the TAPI 3 DLL. Can be the gulAdvise value returned by [IConnectionPoint::Advise](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-iconnectionpoint-advise) during registration of the
[ITTAPIEventNotification](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapieventnotification) outgoing interface.

### `plRegister` [out]

On success, the returned value that is used by
[ITTAPI::UnregisterNotifications](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-unregisternotifications).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plRegister* parameter is not a valid pointer. |
| **TAPI_E_NOT_INITIALIZED** | The TAPI object has not been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

If multiple calls of this method are used on one address, the information about participant calls from a call hub may be confusing if a call that is already being monitored by the application is handed off to it.

The **RegisterCallNotifications** method registers the application as having an interest in monitoring calls or receiving ownership of calls that are of the specified media types. These call privileges are set in the *fMonitor* and *fOwner* parameters.
An application can specify multiple flags to handle multiple media types. Conflicts can arise if multiple applications register for the same address and media type. These conflicts are resolved by a priority scheme in which the user assigns relative priorities to the applications. Users can set application priorities by calling the [ITTAPI::SetApplicationPriority](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-ittapi-setapplicationpriority) function. Only the highest priority application for a given media type will receive ownership (unsolicited) of a call of that media type. Ownership can be received when an incoming call first arrives or when a call is handed off. The [ITBasicCallControl::HandoffDirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-handoffdirect) and [ITBasicCallControl::HandoffIndirect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-handoffindirect) functions are called to hand off ownership of a call to another application. If the user does not assign priorities to the application, and multiple applications open the same line device, by default, the application that called **RegisterCallNotifications** first will have the highest priority.

## See also

[Events overview](https://learn.microsoft.com/windows/desktop/Tapi/events)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[ITTAPIEventNotification](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapieventnotification)

[Register Events code snippet](https://learn.microsoft.com/windows/desktop/Tapi/register-events)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)