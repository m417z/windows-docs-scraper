# IFsrmActionCommand::get_WorkingDirectory

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction),
[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction), and
[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)
classes.]

Retrieves or sets the working directory in which the executable program will run.

This property is read/write.

## Parameters

## Remarks

The path can contain environment variables.

The path must exist when you set the property or the command executes. If the path does not exist when the
command executes, FSRM writes an event to the Application log.

## See also

[IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)

[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction)

[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)