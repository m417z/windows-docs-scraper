# IFaxDevices::get_Item

## Description

The **IFaxDevices::get_Item** method returns a [FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice) object from the [FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices) collection, using its index.

## Parameters

### `vIndex` [in]

Type: **VARIANT**

**VARIANT** that specifies the index of the item to retrieve from the fax device collection. If this parameter is type VT_I2 or VT_I4, the parameter specifies the index of the item to retrieve from the collection. Valid values for the index are in the range from 1 to n, where n is the number of devices returned by a call to the [IFaxDevices::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices-count-vb) method. If this parameter is type VT_BSTR, the parameter is a string containing the unique name of the fax device to retrieve. Other types are not supported.

### `pFaxDevice` [out]

Type: **[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)****

Receives the address of a pointer to a [FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To retrieve an item from the [FaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevices) collection using the device ID, call the [IFaxDevices::get_ItemById](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nf-faxcomex-ifaxdevices-get_itembyid) property.

## See also

[IFaxDevices](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevices)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-configuring-a-fax-device)