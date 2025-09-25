## Description

The **DXGK_USERMODESUBMISSION_CAPS** structure describes KMD's user-mode work submission capabilities.

## Members

### `Flags`

Contains flags that describe the capabilities of the KMD's user-mode work submission.

### `Flags.SecondaryDoorbellSupported`

When set, the KMD supports a secondary doorbell for user-mode work submission.

### `Flags.Reserved`

Reserved for system use.

### `Flags.Value`

An alternative way to access the structure members.

### `DoorbellSizeInBytes`

The memory size of the doorbell, in bytes.

### `SecondaryDoorbellSizeInBytes`

The memory size of the secondary doorbell, in bytes.

### `Reserved[16]`

Reserved for system use.

## Remarks

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)