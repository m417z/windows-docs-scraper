# ITsSbResourceNotificationEx::NotifySessionChangeEx

## Description

Notifies registered plug-ins about state changes in a session object.

## Parameters

### `targetName` [in]

The name of the target.

### `userName` [in]

The user name.

### `domain` [in]

The user domain.

### `sessionId` [in]

Identifies the session that changed.

### `sessionState` [in]

A [TSSESSION_STATE](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-tssession_state) value specifying he type of change that occurred.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification)

[ITsSbResourceNotificationEx](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotificationex)