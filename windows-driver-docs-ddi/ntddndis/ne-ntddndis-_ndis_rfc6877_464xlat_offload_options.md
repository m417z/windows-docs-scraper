# _NDIS_RFC6877_464XLAT_OFFLOAD_OPTIONS enumeration

## Description

The **NDIS_RFC6877_464XLAT_OFFLOAD_OPTIONS** enumeration describes a miniport driver's 464XLAT hardware offload capabilities.

## Constants

### `NDIS_RFC6877_464XLAT_OFFLOAD_NOT_SUPPORTED`

The driver is incapable of 464XLAT hardware offload.

### `NDIS_RFC6877_464XLAT_OFFLOAD_DISABLED`

The driver is capable of 464XLAT hardware offload, but it is disabled.

### `NDIS_RFC6877_464XLAT_OFFLOAD_ENABLED`

The driver is capable of 464XLAT hardware offload, and it is enabled at all times.

### `NDIS_RFC6877_464XLAT_OFFLOAD_ON_DEMAND`

The driver is capable of 464XLAT hardware offload, and it is only enabled on-demand.

## Remarks

## See also

[**NDIS_RFC6877_464XLAT_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_rfc6877_464xlat_offload)

[**NDIS_OFFLOAD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_offload)