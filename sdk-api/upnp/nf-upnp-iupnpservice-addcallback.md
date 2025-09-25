# IUPnPService::AddCallback

## Description

The
**AddCallback** method registers an application's callback with the UPnP framework.

## Parameters

### `pUnkCallback` [in]

Specifies the reference to the interface that contains the callback to register. The object referred to by *pUnkCallback* must either support the
[IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Do not call this method from within a callback; memory corruption occurs.

If more than one callback is registered, the UPnP framework invokes the callbacks sequentially.

The object referred to by *pUnkCallback* must either support the
[IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface. The
**AddCallback** method first queries *pUnkCallback* for the
**IUPnPServiceCallback** interface. If this interface is not supported, the
**AddCallback** method then queries *pUnkCallback* for the **IDispatch** interface. If the **IDispatch** interface is not supported, both checks have failed and the
**AddCallback** method returns E_FAIL.

If only [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) is supported, the [service object](https://learn.microsoft.com/windows/desktop/UPnP/s-gly) invokes the callback by calling [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) with the dispatch ID specified as zero, which indicates the default method. This default **IDispatch** method is passed the same parameters as the
[IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback) method, but the first parameter passed is a string that indicates the reason the callback is invoked. Valid values are VARIABLE_UPDATE and SERVICE_INSTANCE_DIED.

This method has the following arguments:

* The reason the callback is invoked. It is invoked either because a state variable changed (VARIABLE_UPDATE) or because the service instance has become unavailable (SERVICE_INSTANCE_DIED).
* The service object for which the callback is invoked.

If the callback is invoked for a state variable change, the method is passed two additional arguments:

* The name of the variable that changed.
* The new value.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)

[IUPnPServiceCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservicecallback)