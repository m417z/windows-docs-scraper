# COMPOSITE_DEVICE_CAPABILITIES_INIT function

## Description

The **COMPOSITE_DEVICE_CAPABILITIES_INIT** macro initializes the [COMPOSITE_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_composite_device_capabilities) structure.

## Parameters

### `CapabilityFlags`

 A pointer to a caller-allocated [COMPOSITE_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_composite_device_capabilities) structure to be initialized. The macro sets the **CompositeDriverCapabilityFunctionSuspend**
member of **COMPOSITE_DEVICE_CAPABILITIES** to 0.

## See also

[COMPOSITE_DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_composite_device_capabilities)

[How to Register a Composite Device](https://learn.microsoft.com/windows-hardware/drivers/ddi/)

[REGISTER_COMPOSITE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbdlib/ns-usbdlib-_register_composite_device)