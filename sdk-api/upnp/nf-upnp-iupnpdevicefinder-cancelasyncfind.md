# IUPnPDeviceFinder::CancelAsyncFind

## Description

The
**CancelAsyncFind** method cancels an asynchronous search.

## Parameters

### `lFindData` [in]

Specifies the search to cancel. The value of *lFindData* is the value returned by a previous call to
[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind).

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Applications can keep asynchronous searches running until the application exits. Always cancel outstanding operations when exiting an application.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind)

[IUPnPDeviceFinder::StartAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-startasyncfind)