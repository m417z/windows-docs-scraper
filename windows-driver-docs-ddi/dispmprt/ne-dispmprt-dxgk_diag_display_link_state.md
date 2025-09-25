# DXGK_DIAG_DISPLAY_LINK_STATE enumeration

## Description

**DXGK_DIAG_DISPLAY_LINK_STATE** provides the display link state of the target to the operating system (OS) when it is gathering nonintrusive display diagnostic information.

## Constants

### `DXGK_DIAG_DISPLAY_LINK_STATE_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_LINK_STATE_NOTAPPLICABLE`

A driver should return this value if the target is of a type where there is no concept of link or there is no negotiation/handshaking between display hardware and the monitor (for example, VGA targets). This value should never be used for a DisplayPort based target.

### `DXGK_DIAG_DISPLAY_LINK_STATE_STABLE`

A driver should return this value if the link is in a stable state, indicating that negotiation/handshaking has been completed and the link is ready to receive pixel data.

### `DXGK_DIAG_DISPLAY_LINK_STATE_FAILED`

A driver should return this value if the link is in a failed state after attempting to negotiate the bandwidth or any other parameters with a given sink, such as monitor, hub, dongle, etc.

### `DXGK_DIAG_DISPLAY_LINK_STATE_CONTINUOUS_TRAINING`

A driver should return this value if the link is currently being trained. It doesn't matter if this is the first or subsequent link training attempt since it is expected that when the OS calls this diagnostic [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) DDI, training should already been completed in the ideal scenario. a short time frame and hence is not in a stable state.

### `DXGK_DIAG_DISPLAY_LINK_STATE_CONTINUOUS_TRAINING_STABLE`

A driver should return this value if the link is currently in a stable state but only after multiple training attempts. There are scenarios where even though the link seems currently stable it can actually go back to training anytime.

### `DXGK_DIAG_DISPLAY_LINK_STATE_CONTINUOUS_TRAINING_FAILED`

A driver should return this value if the link is currently in the failed state but only after multiple training attempts. The difference between this state and DXGK_DIAG_DISPLAY_LINK_STATE_FAILED is that this value indicates that the link is potentially troublesome and goes into training state often.

## Remarks

The **DXGK_DIAG_DISPLAY_LINK_STATE** enumeration is a member of the [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive).

**DXGK_DIAG_DISPLAY_LINK_STATE** is not DisplayPort-specific. The link state refers to the state of any negotiation/handshaking between display hardware and the monitor before starting to send pixel data.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)