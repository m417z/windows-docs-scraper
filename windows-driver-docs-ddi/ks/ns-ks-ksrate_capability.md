# KSRATE_CAPABILITY structure

## Description

The client uses the KSRATE_CAPABILITY structure in a [KSPROPERTY_STREAM_RATECAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-stream-ratecapability) property request.

## Members

### `Property`

A structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) that specifies the property identifier.

### `Rate`

A structure of type [KSRATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksrate) that specifies the requested rate.