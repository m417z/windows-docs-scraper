# IFaxDeviceIds::Remove

## Description

The **IFaxDeviceIds::Remove** method removes an item from the [FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids) collection.

## Parameters

### `lIndex` [in]

Type: **long**

A **long** value that specifies the index of the item to remove from the collection. Valid values for this parameter are in the range from 1 to n, where n is the number of devices returned by a call to the [IFaxDeviceIds::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids-count-vb) property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** You cannot remove devices from the special **All Devices** routing group.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids)

[IFaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceids)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)