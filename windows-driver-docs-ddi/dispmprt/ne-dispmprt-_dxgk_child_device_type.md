# DXGK_CHILD_DEVICE_TYPE enumeration

## Description

The **DXGK_CHILD_DEVICE_TYPE** enumeration indicates the type of a child device of the display adapter.

## Constants

### `TypeUninitialized`

Indicates that a variable of type **DXGK_CHILD_DEVICE_TYPE** has not yet been assigned a meaningful value.

### `TypeVideoOutput`

Indicates that the child device is a video output. A video output is the circuitry on the display adapter that supplies a video signal to an external or integrated monitor (or other display device). Note that monitors, integrated LCD panels, and other devices that actually display an image are not considered child devices of the display adapter.

### `TypeOther`

Indicates that the child device is not a video output. TV tuners, crossbar switches, and MPEG2 codecs are examples of child devices that are not video outputs.

### `TypeIntegratedDisplay`

Type indicating that this target is permanently connected to an integrated display.

### `TypeLogicalGpu`

This value represents a logical GPU. In a system with multiple physical GPUs, a logical GPU could be a virtual representation of a single GPU or a combination of multiple GPUs working together as a single entity. (Examples include CrossFile and SLI technologies.)

## Remarks

The **ChildDeviceType** member of a [**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor) structure is a **DXGK_CHILD_DEVICE_TYPE** value.

For more information about child devices of display adapters, see [Child Devices of the Display Adapter](https://learn.microsoft.com/windows-hardware/drivers/display/child-devices-of-the-display-adapter) and [Enumerating Child Devices of a Display Adapter](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-child-devices-of-a-display-adapter).

## See also

[**DXGK_CHILD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_descriptor)

[**DxgkDdiQueryChildRelations**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)