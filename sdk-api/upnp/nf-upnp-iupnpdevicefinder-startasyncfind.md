# IUPnPDeviceFinder::StartAsyncFind

## Description

The
**StartAsyncFind** method starts an asynchronous search operation.

## Parameters

### `lFindData` [in]

Specifies the search to start. The value of *lFindData* is the value returned by a previous call to
[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind).

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

You can have more than one
**StartAsyncFind** operation running at the same time; starting another
**StartAsyncFind** does not cancel a previous
**StartAsyncFind** operation.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::CancelAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-cancelasyncfind)