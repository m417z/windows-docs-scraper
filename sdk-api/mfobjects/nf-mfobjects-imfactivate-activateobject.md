# IMFActivate::ActivateObject

## Description

Creates the object associated with this activation object.

## Parameters

### `riid` [in]

Interface identifier (IID) of the requested interface.

### `ppv` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Some Microsoft Media Foundation objects must be shut down before being released. If so, the caller is responsible for shutting down the object that is returned in *ppv*. To shut down the object, do one of the following:

* Call [IMFActivate::ShutdownObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-shutdownobject) on the activation object, or
* Call the object-specific shutdown method. This method will depend on the type of object. Possibilities include:
  + Media sources: Call [IMFMediaSource::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown).
  + Media sinks: Call [IMFMediaSink::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasink-shutdown).
  + Any object that supports the [IMFShutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfshutdown) interface: Call [IMFShutdown::Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfshutdown-shutdown).

The [IMFActivate::ShutdownObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-shutdownobject) method is generic to all object types. If the object does not require a shutdown method, **ShutdownObject** succeeds and has no effect. If you do not know the specific shutdown method for the object (or do not know the object type), call **IMFActivate::ShutdownObject**.

After the first call to **ActivateObject**, subsequent calls return a pointer to the same instance, until the client calls either [ShutdownObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-shutdownobject) or [IMFActivate::DetachObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-detachobject).

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate)