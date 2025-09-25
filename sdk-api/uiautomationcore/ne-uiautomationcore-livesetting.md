# LiveSetting enumeration

## Description

Contains possible values for the LiveSetting property. This property is implemented by provider elements that are part of a live region.

## Constants

### `Off:0`

### `Polite:1`

### `Assertive:2`

#### - LiveSetting_Assertive

The provider element sends change notifications when the content of the live region changes, and a client should immediately notify the user of each change.

#### - LiveSetting_Off

The provider element does not send change notifications when the content of the live region changes. A client application will be aware of changes to the live region only if the client handles other events related to the elements in the live region.

#### - LiveSetting_Polite

The provider element sends change notifications when the content of the live region changes, but a client should not interrupt the user to inform the user of changes. Instead, the client should wait until the user is not performing high-priority actions and wants to receive low-priority notifications.

## See also

[CachedLiveSetting](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement2-get_cachedlivesetting)

[CurrentLiveSetting](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nf-uiautomationclient-iuiautomationelement2-get_currentlivesetting)