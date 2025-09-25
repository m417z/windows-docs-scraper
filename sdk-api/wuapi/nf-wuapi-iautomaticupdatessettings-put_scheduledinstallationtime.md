# IAutomaticUpdatesSettings::put_ScheduledInstallationTime

## Description

[**IAutomaticUpdatesSettings::ScheduledInstallationTime** is no longer supported as of Windows 10.]

Gets and sets the time at which Automatic Updates installs or uninstalls updates.

This property is read/write.

## Parameters

## Remarks

The time is set by using the following values.

| Value | Time |
| --- | --- |
| 0 | 00:00 |
| 1 | 01:00 |
| 2 | 02:00 |
| 3 | 03:00 |
| 4 | 04:00 |
| 5 | 05:00 |
| 6 | 06:00 |
| 7 | 07:00 |
| 8 | 08:00 |
| 9 | 09:00 |
| 10 | 10:00 |
| 11 | 11:00 |
| 12 | 12:00 |
| 13 | 13:00 |
| 14 | 14:00 |
| 15 | 15:00 |
| 16 | 16:00 |
| 17 | 17:00 |
| 18 | 18:00 |
| 19 | 19:00 |
| 20 | 20:00 |
| 21 | 21:00 |
| 22 | 22:00 |
| 23 | 23:00 |

The value of this property is ignored if the value of the [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) property is not **aunlScheduledInstallation**.

**Note** Starting with Windows 8 and Windows Server 2012, **ScheduledInstallationTime** is not supported and will return unreliable values. If you try to modify **ScheduledInstallationTime**, the operation will appear to succeed but will have no effect.

## See also

[IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings)