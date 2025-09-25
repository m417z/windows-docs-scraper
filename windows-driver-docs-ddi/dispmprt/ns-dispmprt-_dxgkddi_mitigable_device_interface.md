# _DXGKDDI_MITIGABLE_DEVICE_INTERFACE structure

## Description

This device interface specifies the parts of the device base address registers that need to be intercepted and mitigated.

These ranges could be sections of the hardware that are protected or could result in crashes or exploits from the guest virtual machine if they were exposed. As part of a defense-in-depth approach, these sensitive hardware regions are exposed and protected not by the user mode device emulator, but instead by the more trusted kernel mode device driver.

## Members

### `Size`

Size.

### `Version`

Represents the DXGKDDI_MITIGABLE_DEVICE_INTERFACE_VERSION.

### `Context`

Device context.

### `InterfaceReference`

Reference.

### `InterfaceDereference`

Dereference.

### `DxgkDdiQueryMitigatedRangeCount`

Called to query the mitigated range count.

### `DxgkDdiQueryMitigatedRanges`

Called to query the mitigated ranges.

## Remarks

This interface is optional but must be implemented for any GPU where a virtual function has hardware resources, which are unsafe to directly expose to a VM. If a driver uses mitigation, it must also provide a user mode emulation DLL that implements the mitigation.
The KMD could decide that the mitigated ranges need remapping and DxgkCbMitigatedRangeUpdate callback is provided to notify Dxgkrnl. Dxgkrnl will re-enumerate mitigated ranges asynchronously.

## See also