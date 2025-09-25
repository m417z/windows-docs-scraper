# IUPnPDeviceFinder::CreateAsyncFind

## Description

The
**CreateAsyncFind** method creates an asynchronous search operation.

## Parameters

### `bstrTypeURI` [in]

Specifies the uniform resource identifier (URI) for which to search.

### `dwFlags` [in]

Specify zero. This parameter is reserved for future use.

### `punkDeviceFinderCallback` [in]

Reference to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface object that specifies the callback that the UPnP framework must use to communicate the results of this asynchronous search.

The object referred to by *pUnkCallback* must support either the
[IUPnPDeviceFinderCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefindercallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface. The object referred to by *pUnkCallback* might support the [IUPnPDeviceFinderAddCallbackWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinderaddcallbackwithinterface) interface, in addition to the **IUPnPDeviceFinderCallback** interface.

### `plFindData` [out]

Reference to a **LONG** that receives the identifier for this particular search. The application must supply this identifier to other asynchronous search methods that are called.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This method returns immediately; the UPnP framework notifies the caller of any search results using the callback specified by *pUnkCallback*. This method returns a search identifier; the caller must use the [IUPnPDeviceFinder::StartAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-startasyncfind) to actually begin the search.

In C++, the object referred to by *pUnkCallback* must support either the [IUPnPDeviceFinderCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefindercallback) interface or the [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface. Optionally, the object referred to by *pUnkCallback* might support the [IUPnPDeviceFinderAddCallbackWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinderaddcallbackwithinterface) interface, in addition to the **IUPnPDeviceFinderCallback** interface. The UPnP framework first queries *pUnkCallback* for the **IUPnPDeviceFinderAddCallbackWithInterface** interface. If the interface is not supported, the UPnP framework next queries *pUnkCallback* for the **IUPnPDeviceFinderCallback** interface. If it is not supported, the UPnP framework then queries *pUnkCallback* for the **IDispatch** interface. If the **IDispatch** interface is not supported, the UPnP framework returns E_FAIL.

In VBScript, the second argument must be **GetRef**(*funcname*), where *funcname* is the name of the callback subroutine.

In Visual Basic, the callback function must be declared with three parameters. The callback function uses the values specified for each parameter:

* *param1* is the Device object of the new device; it is only valid when *param3* is zero.
* *param2* is the UDN of the found or removed device; it is only valid when *param3* is zero or one.
* *param3* is the type of callback. Valid values are:

  0—indicates a new device.

  1—indicates a device has been removed.

  2—indicates the search is complete.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::StartAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-startasyncfind)