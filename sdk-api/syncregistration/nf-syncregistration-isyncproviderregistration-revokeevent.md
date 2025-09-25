# ISyncProviderRegistration::RevokeEvent

## Description

Unregisters the user from the notification of the arrival of new registration
events.

## Parameters

### `hEvent` [in]

The **HANDLE** returned by the [RegisterForEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-registerforevent) method.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified event has not been registered. |

## Remarks

This method closes the specified **HANDLE** and cleans up any related memory.

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)