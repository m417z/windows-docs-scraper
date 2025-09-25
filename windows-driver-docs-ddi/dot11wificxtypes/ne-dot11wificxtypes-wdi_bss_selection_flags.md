## Description

> [!IMPORTANT]
> This topic is part of the [WiFiCx driver model](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx). WiFiCx is the Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The previous Wi-Fi driver model [WDI](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-miniport-driver-design-guide) is in maintenance mode and will only receive high priority fixes.

The **WDI_BSS_SELECTION_FLAGS** enumeration defines flags for BSS selection.

## Constants

### `WDI_BSS_SELECTION_HOST_PREFERRED:0x00000001`

Set for BSS entries that the host prefers to connect to. Non-preferred BSS entries would also be provided to the port, but should only be used for connection if port performs its own BSS ranking.

### `WDI_BSS_SELECTION_RECENT_ASSOCIATION_ERROR:0x00000002`

Set for BSS entries that had recent association failures or were recently disassociated from. This flag is already accounted for by the host when setting WDI_BSS_SELECTION_HOST_PREFERRED.

### `WDI_BSS_SELECTION_FLAGS_AP_REQUESTED_TRANSITION:0x00000004`

Specifies whether this roam was requested by the AP or not (11v BSS Transition management request).

## Remarks

The **WDI_BSS_SELECTION_FLAGS** enum is a value in the [WDI_TLV_BSS_SELECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-bss-selection-parameters) TLV.

## See also

[WDI_TLV_BSS_SELECTION_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/network/wdi-tlv-bss-selection-parameters)