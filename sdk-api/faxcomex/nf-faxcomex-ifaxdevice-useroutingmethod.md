# IFaxDevice::UseRoutingMethod

## Description

The **IFaxDevice::UseRoutingMethod** method adds an inbound fax routing method to or removes a fax routing method ([FaxInboundRoutingMethod](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxinboundroutingmethod)) from the list of routing methods associated with the fax device.

## Parameters

### `bstrMethodGUID` [in]

Type: **BSTR**

Specifies a null-terminated string that uniquely identifies the fax routing method to add or remove.

### `bUse` [in]

Type: **VARIANT_BOOL**

Specifies a Boolean value. If this parameter is equal to **TRUE**, the method adds the fax routing method to the list of inbound methods associated with the fax device. If you set this parameter to **FALSE**, the method removes the routing method from the list.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdevice)

[IFaxDevice](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdevice)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-fax-device-collection)