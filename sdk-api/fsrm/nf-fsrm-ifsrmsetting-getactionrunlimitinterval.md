# IFsrmSetting::GetActionRunLimitInterval

## Description

Gets the time that an action that uses the global run limit interval must wait before the action is run again.

## Parameters

### `actionType` [in]

The action type to limit. For possible values, see the [FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype) enumeration.

### `delayTimeMinutes` [out]

The run limit interval, in minutes, that is used for the action.

## Return value

Returns the following return values:

## See also

[FsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmsetting)

[IFsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmsetting)