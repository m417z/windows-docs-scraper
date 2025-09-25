# ITsSbResourceNotificationEx::NotifyTargetChangeEx

## Description

Notifies registered plug-ins about state changes in a target object.

## Parameters

### `targetName` [in]

The name of the target.

### `targetChangeType` [in]

A value of the [TARGET_CHANGE_TYPE](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-target_change_type) enumeration that specifies the type of change that occurred in a target.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification)

[ITsSbResourceNotificationEx](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotificationex)