# IFsrmActionCommand::get_MonitorCommand

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction),
[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction), and
[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)
classes.]

Retrieves or sets a value that determines whether FSRM will monitor the executable program specified
in the [ExecutablePath](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_executablepath)
property.

This property is read/write.

## Parameters

## Remarks

The [KillTimeOut](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_killtimeout) and
[LogResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_logresult) properties are ignored if this
property is not set to **VARIANT_TRUE**.

## See also

[IFsrmActionCommand](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmactioncommand)

[IFsrmActionCommand::LogResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioncommand-get_logresult)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)

[MSFT_FSRMFMJAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjaction)

[MSFT_FSRMFMJNotificationAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfmjnotificationaction)