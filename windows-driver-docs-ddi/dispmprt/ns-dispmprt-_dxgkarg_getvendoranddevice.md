# _DXGKARG_GETVENDORANDDEVICE structure

## Description

Arguments used to supply the Vendor and Device IDs for a PCI Express SR-IOV Virtual Function (VF) to be used as the basis for the more generic Plug and Play IDs for the VF.

## Members

### `VirtualFunctionIndex`

Zero-based offset of the Virtual Function from the first VF exposed by this Physical Function.

### `VendorId`

To be filled in with the Vendor ID to be used for this function.

### `DeviceId`

To be filled in with the Device ID to be used for this function.

## Remarks

## See also