# AutomaticUpdatesScheduledInstallationDay enumeration

## Description

Defines the days of the week when Automatic Updates installs or uninstalls updates.

## Constants

### `ausidEveryDay:0`

Every day.

### `ausidEverySunday:1`

Every Sunday.

### `ausidEveryMonday:2`

Every Monday.

### `ausidEveryTuesday:3`

Every Tuesday.

### `ausidEveryWednesday:4`

Every Wednesday.

### `ausidEveryThursday:5`

Every Thursday.

### `ausidEveryFriday:6`

Every Friday.

### `ausidEverySaturday:7`

Every Saturday.

## Remarks

Updates are installed on the scheduled day. The updates depend on the settings of the [NotificationLevel](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_notificationlevel) and [ScheduledInstallationTime](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_scheduledinstallationtime) properties of the [IAutomaticUpdatesSettings](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iautomaticupdatessettings) interface.