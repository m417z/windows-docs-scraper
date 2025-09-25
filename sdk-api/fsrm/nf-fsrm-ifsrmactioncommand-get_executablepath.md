# IFsrmActionCommand::get_ExecutablePath

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction),
[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction), and
[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)
classes.]

Retrieves or sets the full path to the executable program or script to run.

This property is read/write.

## Parameters

## Remarks

The path must exist at the time you set the property and when the command executes. If the path does not exist
when the command executes, FSRM writes an event to the Application log.

To execute the command, the user that configured the action must exist in the Administrators group at the time
the command is executed.

Only administrators can have write access to all folders in the path at the time you set the property and when
the command executes. If others have write access when the command executes, FSRM does not execute the command and
writes an event to the Application log.

## See also

[IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)

[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction)

[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)