# IFaxDeviceIds::get_Item

## Description

The **IFaxDeviceIds::get_Item** method represents a device ID from the [FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids) collection.

## Parameters

### `lIndex` [in]

Type: **long**

A value specifying the item to retrieve from the collection. Valid values for this parameter are in the range from 1 to n, where n is the number of devices returned by a call to the [IFaxDeviceIds::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids-count-vb) method.

### `plDeviceId` [out, retval]

Type: **long***

Pointer to a value that receives the item requested.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids)

[IFaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceids)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)