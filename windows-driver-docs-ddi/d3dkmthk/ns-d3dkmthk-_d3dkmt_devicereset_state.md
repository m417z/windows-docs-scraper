# _D3DKMT_DEVICERESET_STATE structure

## Description

The D3DKMT_DEVICERESET_STATE structure identifies reset status.

## Members

### `DesktopSwitched`

A UINT value that specifies whether the desktop that the calling process is created on switched from being visible to being invisible. For example, when the security screen appears because a user pressed CTRL+ALT+DEL, the desktop that the calling process is created on becomes invisible.

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies reset status.

## See also

[D3DKMT_GETDEVICESTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getdevicestate)