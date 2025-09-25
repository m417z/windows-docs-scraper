# IMFMediaSink::Shutdown

## Description

Shuts down the media sink and releases the resources it is using.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_SHUTDOWN** | The media sink was shut down. |

## Remarks

If the application creates the media sink, it is responsible for calling **Shutdown** to avoid memory or resource leaks. In most applications, however, the application creates an activation object for the media sink, and the Media Session uses that object to create the media sink. In that case, the Media Session — not the application — shuts down the media sink. (For more information, see [Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects).)

After this method returns, all methods on the media sink return MF_E_SHUTDOWN, except for **IUnknown** methods and [IMFMediaEventGenerator](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediaeventgenerator) methods. The sink will not raise any events after this method is called.

## See also

[IMFMediaSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasink)

[Media Sinks](https://learn.microsoft.com/windows/desktop/medfound/media-sinks)