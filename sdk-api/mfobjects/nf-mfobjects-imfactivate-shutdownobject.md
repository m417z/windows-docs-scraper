# IMFActivate::ShutdownObject

## Description

Shuts down the created object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If you create an object by calling [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject), call **ShutdownObject** when you are done using the object.

The component that calls [ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject)—not the component that creates the activation object—is responsible for calling **ShutdownObject**. For example, in a typical playback application, the application creates activation objects for the media sinks, but the Media Session calls **ActivateObject**. Therefore the Media Session, not the application, calls **ShutdownObject**.

After **ShutdownObject** is called, the activation object releases all of its internal references to the created object. If you call [ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) again, the activation object will create a new instance of the other object.

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate)