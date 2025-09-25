# IUIAutomationElement2::get_CurrentLiveSetting

## Description

Indicates the type of notifications, if any, that the element sends when the content of the element changes.

This property is read-only.

## Parameters

### `retVal`

## Remarks

This property maps to the Accessible Rich Internet Applications (ARIA) **live** property.

The LiveSetting property is supported by provider elements that are part of a live region. When the content of a live region changes, the provider element can raise a notification. A client application determines whether to notify the user of the changes based on the value of the LiveSetting property.

## See also

[CachedLiveSetting](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement2-get_cachedlivesetting)

[IUIAutomationElement2](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationelement2)

[LiveSetting](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-livesetting)