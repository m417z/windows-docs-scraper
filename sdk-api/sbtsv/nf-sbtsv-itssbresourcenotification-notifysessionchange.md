# ITsSbResourceNotification::NotifySessionChange

## Description

Notifies registered plug-ins about state changes in a session object.

## Parameters

### `changeType` [in]

The type of change that occurred.

### `pSession` [in]

A pointer to a session object. This object is a copy of the object present in the RD Connection Broker store. Any changes to this object do not affect the object in the store.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

RD Connection Broker calls the **NotifySessionChange** method to notify registered plug-ins about state changes in a session object. For example, RD Connection Broker calls this method when a new session is added to the resource plug-in store as a result of a session logon.

## See also

[ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification)