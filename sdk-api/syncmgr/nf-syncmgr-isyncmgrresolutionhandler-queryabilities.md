# ISyncMgrResolutionHandler::QueryAbilities

## Description

Determines what options the conflict presenter will display.

## Parameters

### `pdwAbilities` [out]

Type: **SYNCMGR_RESOLUTION_ABILITIES_FLAGS***

When this method returns, contains one of the [SYNCMGR_RESOLUTION_ABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_abilities) enumerated type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The handler exposes how a conflict can be resolved by calling this method. The result of this method determines what options the conflict presenter displays, and as a result, how other methods in this interface are called.