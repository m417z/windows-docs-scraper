# IDDCX_FEATURE_IMPLEMENTATION enumeration

## Description

A **IDDCX_FEATURE_IMPLEMENTATION** value is used to indicate how a given supported feature is implemented.

## Constants

### `IDDCX_FEATURE_IMPLEMENTATION_UNINITIALIZED:0`

Indicates that an **IDDCX_FEATURE_IMPLEMENTATION** variable has not yet been assigned a meaningful value.

### `IDDCX_FEATURE_IMPLEMENTATION_NONE:1`

The feature is not implemented.

### `IDDCX_FEATURE_IMPLEMENTATION_HARDWARE:2`

The feature is implemented and hardware is used in the implementation. For example, the adapter display pipeline blends the hardware cursor image into the signal sent to the monitor.

### `IDDCX_FEATURE_IMPLEMENTATION_SOFTWARE:3`

The feature is implemented and software is used in the implementation. For example, the driver supports hardware cursor by blending the cursor image into the display pixels as part of the processing.

## See also

[**IDDCX_ENDPOINT_DIAGNOSTIC_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_endpoint_diagnostic_info)