# FWPS_ALE_ENDPOINT_ENUM_TEMPLATE0 structure

## Description

The **FWPS_ALE_ENDPOINT_ENUM_TEMPLATE0** structure specifies a template for application layer enforcement
(ALE) endpoints to be enumerated.

**Note** **FWPS_ALE_ENDPOINT_ENUM_TEMPLATE0** is a specific version of **FWPS_ALE_ENDPOINT_ENUM_TEMPLATE**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `localSubNet`

The local subnet portion of the enumeration template.

### `remoteSubNet`

The remote subnet portion of the enumeration template.

### `ipProtocol`

The IP protocol portion of the enumeration template.

### `localPort`

The local port portion of the enumeration template.

### `remotePort`

The remote port portion of the enumeration template.

## Remarks

This structure can be used to narrow the results when enumerating endpoints. If used, it is specified
when the enumeration handle is created by calling
[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0). Any populated members are used to limit the enumeration results
returned by
[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpsaleendpointenum0).

## See also

[FwpsAleEndpointCreateEnumHandle0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpsaleendpointcreateenumhandle0)

[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/fwpsk/nf-fwpsk-fwpsaleendpointenum0)