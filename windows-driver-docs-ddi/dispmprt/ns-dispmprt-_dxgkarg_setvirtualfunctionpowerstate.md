# _DXGKARG_SETVIRTUALFUNCTIONPOWERSTATE structure

## Description

Used to set virtual function power state.

## Members

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `PowerState`

New power state for the device. See the definition of DEVICE_POWER_STATE for more information.

### `Wake`

Boolean value indicating whether the device should have its wake signal (PME for PCI Express devices) armed as it goes into the low power state. This value will be FALSE if PowerState is PowerDeviceD0.

## Remarks

## See also