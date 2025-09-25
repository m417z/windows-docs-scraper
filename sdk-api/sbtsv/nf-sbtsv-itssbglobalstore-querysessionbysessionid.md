# ITsSbGlobalStore::QuerySessionBySessionId

## Description

Retrieves the [ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession) object associated with the given
session ID.

## Parameters

### `ProviderName` [in]

The resource plug-in provider name that owns the target.

### `dwSessionId` [in]

The session ID.

### `TargetName` [in]

The name of the target computer on which this session is present.

### `ppSession` [out]

A pointer to a pointer to a session object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

## Return value

This method can return one of these values.

## Remarks

Any changes made to the target objects returned by this method do not affect the target objects stored
in Remote Desktop Connection Broker (RD Connection Broker). The target objects returned are copies of the target objects in RD Connection Broker.

## See also

[ITsSbGlobalStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbglobalstore)