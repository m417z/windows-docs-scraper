# _DXGK_HARDWARE_CONTENT_PROTECTION_TEARDOWN_FLAGS enumeration

## Description

**DXGK_HARDWARE_CONTENT_PROTECTION_TEARDOWN_FLAGS** provides additional information to the driver in a [DxgkCbHardwareContentProtectionTeardown](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_hardwarecontentprotectionteardown) call.

## Constants

### `DXGK_HARDWARE_CONTENT_PROTECTION_TEARDOWN_FLAG_PREEMPTIVE`

Indicates that the [DxgkCbHardwareContentProtectionTeardown](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_hardwarecontentprotectionteardown) callback is being preemptively called prior to tear-down event actually occurring.

## See also

[DxgkCbHardwareContentProtectionTeardown](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_hardwarecontentprotectionteardown)