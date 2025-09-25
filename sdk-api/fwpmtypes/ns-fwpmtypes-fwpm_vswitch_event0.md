## Description

The **FWPM_VSWITCH_EVENT0** structure contains information about a vSwitch event.

## Members

### `eventType`

Type: [FWPM_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_vswitch_event_type)

The type of vSwitch event.

### `vSwitchId`

Type: **wchar_t***

GUID that identifies a vSwitch.

### `positionInfo`

Available when **eventType** is **FWPM_VSWITCH_EVENT_FILTER_ADD_TO_FILTER_ENGINE_NOT_IN_REQUIRED_POSITION**.

### `positionInfo.numvSwitchFilterExtensions`

**Type: **ULONG**

The number of vSwitch filter extensions.

### `positionInfo.vSwitchFilterExtensions`

**Type: **LPWSTR***

size_is(numvSwitchFilterExtensions)

Array of strings identifying other vSwitch extensions.

### `reorderInfo`

Available when **eventType** is **FWPM_VSWITCH_EVENT_FILTER_ENGINE_REORDER**.

### `reorderInfo.inRequiredPosition`

**Type: **BOOL**

True if the filter engine is in the required position to correctly enforce committed filters; otherwise, false.

### `reorderInfo.numvSwitchFilterExtensions`

**Type: **ULONG**

The number of vSwitch filter extensions.

### `reorderInfo.vSwitchFilterExtensions`

**Type: **LPWSTR***

size_is(numvSwitchFilterExtensions)

Array of strings identifying other vSwitch extensions.

## Remarks

For the unnamed union, switch_is(eventType), switch_type(FWPM_VSWITCH_EVENT_TYPE).

**FWPM_VSWITCH_EVENT0** is a specific implementation of FWPM_VSWITCH_EVENT. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_VSWITCH_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_vswitch_event_type)**********