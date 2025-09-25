# IFaxDevices::get__NewEnum

## Description

The **IFaxDevices::get__NewEnum** method returns a reference to an enumerator object that you can use to iterate through the [FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices) collection.

## Parameters

### `ppUnk` [out, retval]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)****

Receives an indirect pointer to the enumerator object's [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface for the collection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In Microsoft Visual Basic, you do not need to use the **_NewEnum** property, because it is automatically used in the implementation of **For Each ... Next**.

## See also

[FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices)

[IFaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevices)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-device-providers)