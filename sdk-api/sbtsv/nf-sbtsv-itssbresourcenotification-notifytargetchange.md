# ITsSbResourceNotification::NotifyTargetChange

## Description

Notifies registered plug-ins about state changes in a target object.

## Parameters

### `TargetChangeType` [in]

A value of the [TARGET_CHANGE_TYPE](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-target_change_type) enumeration that specifies the type of change that occurred in a target.

### `pTarget` [in]

A pointer to a target object. This object is a copy of the object present in the RD Connection Broker store. Any changes to this object do not affect the object in the store.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

RD Connection Broker calls the **NotifyTargetChange** method to notify registered plug-ins about state changes in a target object. For example, RD Connection Broker calls this method when a new session is added to the resource plug-in store as a result of a session logon.

## See also

[ITsSbResourceNotification](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcenotification)

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)

[TARGET_CHANGE_TYPE](https://learn.microsoft.com/windows/win32/api/sessdirpublictypes/ne-sessdirpublictypes-target_change_type)