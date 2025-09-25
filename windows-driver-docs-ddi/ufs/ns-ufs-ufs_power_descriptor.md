# UFS_POWER_DESCRIPTOR structure

## Description

**UFS_POWER_DESCRIPTOR** contains information about the power capabilities and power states of the device.

## Members

### `bLength`

Specifies the length, in bytes, of this descriptor.

### `bDescriptorIDN`

Specifies the type of the descriptor. This descriptor will have a value of **UFS_DESC_POWER_IDN**.

### `wActiveICCLevelsVCC`

Specifies the maximum VCC current value for
each UFS_bActiveICCLevel, based on the index value.

### `wActiveICCLevelsVCCQ`

Specifies the maximum VCCQ current value for
each UFS_bActiveICCLevel, based on the index value.

### `wActiveICCLevelsVCCQ2`

Specifies the maximum VCCQ current value for
each UFS_bActiveICCLevel, based on the index value.