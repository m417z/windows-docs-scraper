# POST_UPGRADE_VERSION_INFO structure

## Description

Represents post-upgrade state information for the cluster service.

## Members

### `newMajorVersion`

The major version of the cluster service after the upgrade.

### `newUpgradeVersion`

The minor version of the cluster service after the update.

### `oldMajorVersion`

The major version of the cluster service before the upgrade.

**Tip** In some error conditions this field can be zero.

### `oldUpgradeVersion`

The minor version of the cluster service before the upgrade.

**Tip** In some error conditions this field can be zero.

### `reserved`

Reserved.

## See also

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)