# IAutomaticUpdatesSettings::get_ScheduledInstallationDay

## Description

[**IAutomaticUpdatesSettings::ScheduledInstallationDay** is no longer supported as of Windows 10.]

Gets and sets the days of the week on which Automatic Updates installs or uninstalls updates.

This property is read/write.

## Parameters

## Remarks

The value of this property is ignored if the value of the [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) property is not **aunlScheduledInstallation**.

**Note** Starting with Windows 8 and Windows Server 2012, **ScheduledInstallationDay** is not supported and will return unreliable values. If you try to modify **ScheduledInstallationDay**, the operation will appear to succeed but will have no effect.

## See also

[IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings)