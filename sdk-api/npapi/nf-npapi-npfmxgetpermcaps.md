# NPFMXGetPermCaps function

## Description

Retrieves the capabilities of the permission editor. The return value is a bitmask that indicates which of the **Security** menu items in File Manager are to be enabled.

## Parameters

### `lpDriveName` [in]

Pointer to the name of the drive currently selected in File Manager.

## Return value

A bitmask that indicates what permission capability the user has on the selected drive. The bitmask is a combination of the following flags.

| Return code | Description |
| --- | --- |
| **WNPERMC_PERM** | The **Permissions** menu item is enabled. |
| **WNPERMC_AUDIT** | The **Auditing** menu item is enabled. |
| **WNPERMC_OWNER** | The **Owner** menu item is enabled. |