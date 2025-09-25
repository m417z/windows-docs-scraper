# _DXGK_INTEGRATEDDISPLAYFLAGS structure

## Description

Flags which describe simple properties of an integrated display.

## Members

### `UndockedOrientation`

Orientation of the integrated panel when the system is undocked.
In most systems, the integrated panel is installed such that the native orientation of the panel matches the default orientation of the system so DXGK_DPO_0 (zero) would be used. An example where this would be non-zero is if a natively portrait panel is used in a laptop device.

### `DockedOrientation`

Orientation of the integrated panel when the system is docked. If the system does not support docking, this value will not be used.

In most systems, the integrated panel is installed such that the native orientation of the panel matches the default orientation of the system so DXGK_DPO_0 (zero) would be used. An example where this would be non-zero is if a natively portrait panel is used in a small tablet and the dock holds the tablet in a landscape orientation.

### `Reserved`

This value is reserved for system use.

### `Value`

UINT used to operate on the combined bit-fields.