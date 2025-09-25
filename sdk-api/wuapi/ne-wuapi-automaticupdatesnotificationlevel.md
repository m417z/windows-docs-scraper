# AutomaticUpdatesNotificationLevel enumeration

## Description

Defines the possible ways in which elevated users are notified about Automatic Updates events.

## Constants

### `aunlNotConfigured:0`

Automatic Updates is not configured by the user or by a Group Policy administrator. Users are periodically prompted to configure Automatic Updates.

### `aunlDisabled:1`

Automatic Updates is disabled. Users are not notified of important updates for the computer.

### `aunlNotifyBeforeDownload:2`

Automatic Updates prompts users to approve updates before it downloads or installs the updates.

### `aunlNotifyBeforeInstallation:3`

Automatic Updates automatically downloads updates, but prompts users to approve the updates before installation.

### `aunlScheduledInstallation:4`

Automatic Updates automatically installs updates according to the schedule that is specified by the user or by the [IAutomaticUpdatesSettings.ScheduledInstallationDay](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_scheduledinstallationday) and [IAutomaticUPdatesSettings.ScheduledInstallationTime](https://learn.microsoft.com/windows/desktop/api/wuapi/nf-wuapi-iautomaticupdatessettings-get_scheduledinstallationtime) properties. This setting is the recommended setting.