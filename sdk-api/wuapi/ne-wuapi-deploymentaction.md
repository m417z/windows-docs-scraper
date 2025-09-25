# DeploymentAction enumeration

## Description

Defines the action for which an update is explicitly deployed.

## Constants

### `daNone:0`

No explicit deployment action is specified on the update. The update inherits the value from its bundled updates.

### `daInstallation:1`

The update should be installed on the computer and/or for the specified user.

### `daUninstallation:2`

The update should be uninstalled from the computer and/or for the specified user.

### `daDetection:3`

The update is deployed only to determine the applicability of the update. The update will not be installed.

### `daOptionalInstallation:4`

The update may be installed on the computer and/or for the specified user.