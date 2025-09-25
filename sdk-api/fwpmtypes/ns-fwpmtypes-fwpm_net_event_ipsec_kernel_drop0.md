# FWPM_NET_EVENT_IPSEC_KERNEL_DROP0 structure

## Description

The **FWPM_NET_EVENT_IPSEC_KERNEL_DROP0** structure contains information that describes an IPsec kernel drop event.

## Members

### `failureStatus`

Contains the error code for the failure.

### `direction`

An [FWP_DIRECTION](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_direction) value that specifies whether the dropped packet is inbound or outbound.

### `spi`

Contains the security parameters index (SPI) on the IPsec header of the packet. This will be 0 for clear text packets. The **IPSEC_SA_SPI** is identical to a **UINT32**.

### `filterId`

Filter ID that corresponds to the IPsec callout filter. This will be available only if the packet was dropped by the IPsec callout.

### `layerId`

Layer ID that corresponds to the IPsec callout filter. This will be available only if the packet was dropped by the IPsec callout.

## Remarks

**FWPM_NET_EVENT_IPSEC_KERNEL_DROP0** is a specific implementation of FWPM_NET_EVENT_IPSEC_KERNEL_DROP. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.