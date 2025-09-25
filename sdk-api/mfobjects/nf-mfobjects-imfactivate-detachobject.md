# IMFActivate::DetachObject

## Description

Detaches the created object from the activation object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |

## Remarks

The activation object releases all of its internal references to the created object. If you call [ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) again, the activation object will create a new instance of the other object.

The **DetachObject** method does not shut down the created object. If the **DetachObject** method succeeds, the client must shut down the created object. This rule applies only to objects that have a shutdown method or that support the [IMFShutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfshutdown) interface. See the remarks for [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject).

Implementation of this method is optional. If the activation object does not support this method, the method returns E_NOTIMPL.

## See also

[Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects)

[IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate)