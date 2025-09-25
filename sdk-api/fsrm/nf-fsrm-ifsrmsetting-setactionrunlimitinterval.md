# IFsrmSetting::SetActionRunLimitInterval

## Description

Sets the time that an action that uses the global run limit interval must wait before the action is run again.

## Parameters

### `actionType` [in]

The action type to limit. For possible values, see the [FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype) enumeration.

### `delayTimeMinutes` [in]

The run limit interval, in minutes, to use for the action. The default is 60 minutes.

## Return value

The method returns the following return values.

## Remarks

Applies to actions that have the [IFsrmAction::RunLimitInterval](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmaction-get_runlimitinterval) property set to –1.

This property specifies the interval that should occur before the action is run again if the global run limit interval is used. For example, if the interval has expired since the action last ran, the server will run the action again in response to an event; otherwise, the server cannot run the action again.

## See also

[FsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmsetting)

[IFsrmSetting](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmsetting)