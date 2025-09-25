# IFaxDevices::get_ItemById

## Description

The **IFaxDevices::get_ItemById** method returns a [FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice) object from the [FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices) collection, using its device ID.

## Parameters

### `lId` [in]

Type: **long**

The unique ID of the device to retrieve.

### `ppFaxDevice` [out, retval]

Type: **ppFaxDevice****

A [FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To retrieve an item from the [FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices) collection using the device's index, call the [Item](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices-item) property.

## See also

[FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices)

[IFaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevices)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-fax-device-collection)