# MsiEndTransaction function

## Description

The **MsiEndTransaction** function can commit or roll back all the installations belonging to the transaction opened by the [MsiBeginTransaction](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msibegintransactiona) function. This function should be called by the current owner of the transaction.

**[Windows Installer 4.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-4-0):** Not supported. This function is available beginning with Windows Installer 4.5.

## Parameters

### `dwTransactionState` [in]

The value of this parameter determines whether the installer commits or rolls back all the installations belonging to the transaction. The value can be one of the following.

| Value | Meaning |
| --- | --- |
| MSITRANSACTIONSTATE_ROLLBACK | Performs a [Rollback Installation](https://learn.microsoft.com/windows/desktop/Msi/rollback-installation) to undo changes to the system belonging to the transaction opened by the [MsiBeginTransaction](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msibegintransactiona) function. |
| MSITRANSACTIONSTATE_COMMIT | Commits all changes to the system belonging to the transaction. Runs any [Commit Custom Actions](https://learn.microsoft.com/windows/desktop/Msi/commit-custom-actions) and commits to the system any changes to Win32 or common language runtime assemblies. Deletes the rollback script, and after using this option, the transaction's changes can no longer be undone with a [Rollback Installation](https://learn.microsoft.com/windows/desktop/Msi/rollback-installation). |

## Return value

The **MsiEndTransaction** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | A transaction can be ended only by the current owner. |
| **ERROR_INSTALL_FAILURE** | An installation belonging to the transaction could not be completed. |
| **ERROR_INSTALL_ALREADY_RUNNING** | An installation belonging to the transaction is still in progress. |
| **ERROR_ROLLBACK_DISABLED** | An installation belonging to the transaction did not complete. During the installation, the [DisableRollback](https://learn.microsoft.com/windows/desktop/Msi/disablerollback-action) action disabled [rollback installations](https://learn.microsoft.com/windows/desktop/Msi/rollback-installation) of the package. The installer rolls back the installation up to the point where rollback was disabled, and the function returns this error. |

## See also

[Multiple Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)