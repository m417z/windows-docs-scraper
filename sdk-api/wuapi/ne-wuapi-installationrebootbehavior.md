# InstallationRebootBehavior enumeration

## Description

The **InstallationRebootBehavior** enumeration defines the possible restart behaviors for an update. The **InstallationRebootBehavior** enumeration applies to the installation and uninstallation of updates.

## Constants

### `irbNeverReboots:0`

The update never requires a system restart during or after an installation or an uninstallation.

### `irbAlwaysRequiresReboot:1`

The update always requires a system restart after a successful installation or uninstallation.

### `irbCanRequestReboot:2`

The update can request a system restart after a successful installation or uninstallation.