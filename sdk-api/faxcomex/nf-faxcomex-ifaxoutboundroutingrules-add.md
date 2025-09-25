# IFaxOutboundRoutingRules::Add

## Description

The **IFaxOutboundRoutingRules::Add** method adds an outbound routing rule ([IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule) interface) to the collection defined by the [IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules) interface.

## Parameters

### `lCountryCode`

Type: **long**

A **long** value that specifies the country/region code to associate with the outbound routing rule. Specifying [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) will add a rule that applies to any country/region code.

### `lAreaCode`

Type: **long**

Specifies a **long** value that indicates the area code to associate with the outbound routing rule. Specifying [frrcANY_CODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_routing_rule_code_enum) will add a rule that applies to any area code within the specified country/region code.

### `bUseDevice`

Type: **VARIANT_BOOL**

Specifies a Boolean value that indicates whether the outbound routing rule points to a single fax device rather than to a group of devices.

### `bstrGroupName`

Type: **BSTR**

Specifies a null-terminated string that contains the name of the outbound routing group to which the new routing rule belongs. If *bUseDevice* is set to **TRUE**, this should be an empty string.

### `lDeviceId`

Type: **long**

Specifies the device to associate with the outbound routing rule. If *bUseDevice* is set to **FALSE**, this parameter is ignored.

### `pFaxOutboundRoutingRule` [out, retval]

Type: **[IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule)****

An address of a pointer that receives a [IFaxOutboundRoutingRule](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrule) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can also return remote procedure call (RPC) return values. For more information, see [RPC Return Values](https://learn.microsoft.com/windows/desktop/Rpc/rpc-return-values).

To read or to write to this property, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxOutboundRoutingRules](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutboundroutingrules)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-creating-and-managing-outbound-routing-rules)