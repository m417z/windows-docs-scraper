# UI_CONTEXTAVAILABILITY enumeration

## Description

Specifies values that identify the availability of a [contextual tab](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-element-ribbon-contextualtabs).

## Constants

### `UI_CONTEXTAVAILABILITY_NOTAVAILABLE:0`

A contextual tab is not available for the selected object.

### `UI_CONTEXTAVAILABILITY_AVAILABLE:1`

A contextual tab is available for the selected object. The tab is not the active tab.

### `UI_CONTEXTAVAILABILITY_ACTIVE:2`

A contextual tab is available for the selected object. The tab is the active tab.

## Remarks

A contextual tab is displayed based on the **UI_CONTEXTAVAILABILITY** value in [UI_PKEY_ContextAvailable](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-contextavailable).

## See also

[Constants and Enumerations](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-enumerations)

[UI_PKEY_ContextAvailable](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties-uipkey-contextavailable)