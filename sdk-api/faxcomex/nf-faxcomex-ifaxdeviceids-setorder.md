# IFaxDeviceIds::SetOrder

## Description

The **IFaxDeviceIds::SetOrder** method changes the order of a device in the ordered [FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids) collection.

## Parameters

### `lDeviceId` [in]

Type: **long**

Specifies the device ID of the device whose order you want to change.

### `lNewOrder` [in]

Type: **long**

Specifies the new position of the device in the order.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You identify the device with its device ID, and then choose a new place for it in the order. If you move the device closer to the top of the order, the devices below that position in the order will drop down to accommodate the change. If you move the device closer to the bottom of the order, the devices above that position in the order will move up to fill the gap caused by the change.

In a fax device group, the relative order of the devices within the group is significant. When the fax service initiates an outgoing job, it attempts to select the first fax device in the device group. If that device is not available, the service selects the next available device that follows in rank order, and so on. For more information, see [Fax Device Groups](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-groups).

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids)

[IFaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceids)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)