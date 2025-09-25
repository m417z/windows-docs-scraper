# DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY enumeration

## Description

**DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY** provides basic display topology information to the operating system (OS) when it is gathering nonintrusive display diagnostic information.

## Constants

### `DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY_UNINITIALIZED`

Reserved for OS use during diagnostic initialization.

### `DXGK_DIAG_DISPLAY_CONNECTED_DIRECTLY`

The monitor is connected directly to the graphics card.

### `DXGK_DIAG_DISPLAY_CONNECTED_INDIRECTLY_CONVERTOR`

The monitor is connected indirectly to the graphics card via a converter/connector. In most cases, the driver can only detect active converters.

### `DXGK_DIAG_DISPLAY_CONNECTED_INDIRECTLY_HUB`

The monitor is connected indirectly to the graphics card via a hub.

### `DXGK_DIAG_DISPLAY_CONNECTED_INDIRECTLY`

The monitor is connected indirectly to the graphics card but the driver cannot determine whether it is connected via a hub or a converter.

### `DXGK_DIAG_DISPLAY_CONNECTED_UNKNOWN`

The driver cannot determine whether the monitor is connected directly or indirectly to the graphics card. This value should be used rarely, such as in cases where the connector is a pass through.

## Remarks

The **DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY** enumeration is a member of the [**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive) structure. It is used while gathering display diagnostic information via calls to [**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive).

Dongles and hubs can increase the failure points that can occur during monitor enumeration and negotiations. The operating system (OS) can use the value of **DXGK_DIAG_BASIC_DISPLAY_TOPOLOGY** to determine whether to collect more detailed topology information, if available (for example using the DP AUX DDIs), to determine the current state of the hub and/or dongles to look for the culprit component.

## See also

[**DXGK_DISPLAYSTATE_NONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgk_displaystate_nonintrusive)

[**DXGKARG_GETDISPLAYSTATENONINTRUSIVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-dxgkarg_getdisplaystatenonintrusive)

[**DxgkDdiGetDisplayStateNonIntrusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_getdisplaystatenonintrusive)

[**DXGKDDI_DPAUXIOTRANSMISSION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_dpauxiotransmission)