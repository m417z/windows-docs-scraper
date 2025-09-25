# ISyncProviderRegistration::RegisterForEvent

## Description

Registers the user to receive notification of the arrival of new registration
events that occur when changes are made to the registration store.

## Parameters

### `phEvent` [out]

A **HANDLE** to a synchronization event that is used to notify
the caller about the arrival of new registration
events.

**Note** The caller must not **Close** the returned **HANDLE**. The registration store will manage the memory for the **HANDLE** and will close it when the event is revoked by passing the **HANDLE** to [RevokeEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-revokeevent), or before the store object is freed from memory.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |

## Remarks

The **HANDLE** returned by this method is used by the [GetChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-getchange) method. The event will only be set once from the **RegisterForEvent** call. Any subsequent notifications will only occur when the user calls the **GetChange** method.

To unregister from this event notification system, call the [RevokeEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-revokeevent) method.

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)