# HW_TRACING_ENABLED callback function

## Description

The **HwStorTracingEnabled** callback routine enables the Storport to notify a miniport that event tracing is enabled.

## Parameters

### `HwDeviceExtension`

[in] A pointer to the miniport driver's per-HBA storage area.

### `Enabled` [in]

True to enable tracing in the miniport. Otherwise, false.

## Remarks

The name *HwStorTracingEnabled* is placeholder text for the actual routine name. The actual prototype of this routine is defined in *Storport.h* as follows:

```cpp
typedef
VOID
HW_TRACING_ENABLED (
    _In_ PVOID HwDeviceExtension,
    _In_ BOOLEAN Enabled
    );
```

## See also

[**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1)