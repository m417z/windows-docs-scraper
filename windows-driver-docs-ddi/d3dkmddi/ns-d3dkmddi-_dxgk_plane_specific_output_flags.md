# _DXGK_PLANE_SPECIFIC_OUTPUT_FLAGS structure

## Description

A structure containing the flags that apply to a plane set by the driver.

## Members

### `FlipConvertedToImmediate`

Indicates that the flip was converted to an immediate flip rather than a VSYNC flip. The driver sets FlipConvertedToImmediate when the current line is less than DXGK_MULTIPLANE_OVERLAY_PLANE3.MaxImmediateFlipLine.

### `PostPresentNeeded`

 Indicates that scheduler must call DXGDDI_POSTMULTIPLANEOVERLAYPRESENT for this specific plane. The driver must only set this flag for immediate flips.

### `HsyncInterruptCompletion`

Indicates that the scheduler should not assume that the immediate flip for this plane is completed upon the return from DdiSetVidPnSourceAddressWithMultiPlaneOverlay3 DDI. . Instead, the OS will only assume the immediate flip is completed when it receives a CrtcVsyncWithMultiPlaneOverlay2 interrupt notification with the PresentId greater or equal to pending immediate flip request. CrtcVsyncWithMultiPlaneOverlay2 interrupt notification for this flip may be an HsyncFlipCompletion, or it may be a regular VSync notification. The driver must only set this flag for immediate flips.

### `Reserved`

This member is reserved and should be set to zero. Setting this member to zero is equivalent to setting the remaining 27 bits (0xFFFFFFE0) of the 32-bit **Value** member to zeros.

### `Value`