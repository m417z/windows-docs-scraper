# _D3DKMT_OUTPUTDUPLPRESENTFLAGS structure

## Description

Describes options for a [Desktop Duplication API](https://learn.microsoft.com/windows/desktop/direct3ddxgi/desktop-dup-api) swapchain present operation.

## Members

### `ProtectedContentBlankedOut`

Specifies whether the desktop image might contain protected content that was already blanked out (black) in the desktop image.

**TRUE** if protected content was already blanked out; otherwise, **FALSE**.

The application can use this information to notify the remote user that some of the desktop content might be protected and therefore not visible.

### `RemoteSession`

Specifies if the present operation is directed to a remote session

**TRUE** if the present operation is directed to a remote session; otherwise, **FALSE**.

If **TRUE**, the present operation will go through a GDI path.

### `FullScreenPresent`

Specifies if the present operation is to the full screen.

**TRUE** if the present operation is to the full screen; otherwise, **FALSE**.

### `PresentIndirect`

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 29 bits (0xFFFFFFF8) of the 32-bit **Value** member to zeros.

### `Value`

A 32-bit value that identifies the DDA present options.