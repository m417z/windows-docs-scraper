# NDIS_PD_COUNTER_TYPE enumeration

## Description

The **NDIS_PD_COUNTER_TYPE** enumeration defines types of PacketDirect Provider Interface (PDPI) counters. Its enumeration values are used in the **Type** member of the [NDIS_PD_COUNTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_counter_parameters) structure.

## Constants

### `PDCounterTypeUnknown`

The counter type is not known.

### `PDCounterTypeReceiveQueue`

The counter is a receive queue counter.

### `PDCounterTypeTransmitQueue`

The counter is a transmit queue counter.

### `PDCounterTypeReceiveFilter`

The counter is a receive filter counter.

### `PDCounterTypeMax`

The maximum value for this enumeration. This value might change in future versions of NDIS header files and binaries.

## See also

[NDIS_PD_COUNTER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_pd_counter_parameters)