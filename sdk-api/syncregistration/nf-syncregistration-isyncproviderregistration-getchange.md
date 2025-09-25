# ISyncProviderRegistration::GetChange

## Description

 Gets an [ISyncRegistrationChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncregistrationchange) object that represents a new registration event.

## Parameters

### `hEvent` [in]

A **HANDLE** returned by the [RegisterForEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-registerforevent) method.

### `ppChange` [out]

The [ISyncRegistrationChange](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncregistrationchange) object
that contains the event, and the ID of the synchronization provider or synchronization provider configuration UI that has changed.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | All outstanding events have been retrieved. |
| **E_POINTER** | Invalid pointer. |

## Remarks

This method resets the event that is passed in so that it will be set on a subsequent change in the registration store. In order to retrieve all events from the store, this method should be called until **S_FALSE** is returned and *ppChange* is **NULL**.

This method returns the changes that have occurred since [RegisterForEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nf-syncregistration-isyncproviderregistration-registerforevent) or **GetChange** (whichever happened last) was last called for the given **HANDLE**. This means that if multiple changes are made to an item before **GetChange** can be called, these changes will be represented as a single change object returned from **GetChange**. In the case of an item being registered and unregistered between calls, no change will be returned.

## See also

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)