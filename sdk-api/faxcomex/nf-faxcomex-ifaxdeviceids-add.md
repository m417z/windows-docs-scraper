# IFaxDeviceIds::Add

## Description

The **IFaxDeviceIds::Add** method adds a fax device to the [FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids) collection, using the device's ID.

## Parameters

### `lDeviceId` [in]

Type: **long**

A **long** value that specifies the ID of the fax device to add to the collection.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can also return remote procedure call (RPC) return values. For more information, see [RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

**Note** You cannot add devices to the special **All Devices** routing group. Also, you can only add valid device IDs. You can obtain the valid ID of a device in the [FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids) collection through the [Id](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice-id-vb) property.

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdeviceids)

[IFaxDeviceIds](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdeviceids)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-outbound-routing-groups)