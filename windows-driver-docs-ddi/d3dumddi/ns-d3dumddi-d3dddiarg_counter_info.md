# D3DDDIARG_COUNTER_INFO structure

## Description

Describes info to manipulate counters.

## Members

### `LastDeviceDependentCounter`

A value of type [D3DDDIQUERYTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) that identifies the largest device-dependent counter identifier that the device supports. If none are supported, the user-mode display driver must set the value to 0; otherwise, the driver sets the value to greater than or equal to **D3DDDIQUERYTYPE_COUNTER_DEVICE_DEPENDENT**.

### `NumSimultaneousCounters`

The number of simultaneously active counters that the driver supports.