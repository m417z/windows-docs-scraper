# ITsSbResourcePluginStore::SetTargetState

## Description

Sets the state of a target object.

## Parameters

### `targetName` [in]

The name of the target.

### `newState` [in]

The [TARGET_STATE](https://learn.microsoft.com/windows/desktop/api/sessdirpublictypes/ne-sessdirpublictypes-target_state) value to set.

### `pOldState` [out]

The previous state of the target.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITsSbResourcePluginStore](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbresourcepluginstore)

[ITsSbTarget](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtarget)