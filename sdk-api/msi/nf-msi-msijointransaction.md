# MsiJoinTransaction function

## Description

The **MsiJoinTransaction** function requests that the Windows Installer make the current process the owner of the [transaction](https://learn.microsoft.com/windows/desktop/Msi/t-gly) installing the multiple-package installation.

**[Windows Installer 4.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-4-0):** Not supported. This function is available beginning with Windows Installer 4.5.

## Parameters

### `hTransactionHandle` [in]

The transaction ID, which identifies the transaction and is the identifier returned by the [MsiBeginTransaction](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msibegintransactiona) function.

### `dwTransactionAttributes` [in]

Attributes of the multiple-package installation.

| Value | Meaning |
| --- | --- |
| 0 | When 0 or no value is set, Windows Installer closes the UI from the previous installation. |
| MSITRANSACTION_CHAIN_EMBEDDEDUI | Set this attribute to request that the Windows Installer not shutdown the embedded UI until the transaction is complete. |
| MSITRANSACTION_JOIN_EXISTING_EMBEDDEDUI | Set this attribute to request that the Windows Installer transfer the embedded UI from the original installation. If the original installation has no embedded UI, setting this attribute does nothing. |

### `phChangeOfOwnerEvent` [out]

This parameter returns a handle to an event that is set when the **MsiJoinTransaction** function changes the owner of the transaction to a new owner. The current owner can use this to determine when ownership of the transaction has changed. Leaving a transaction without an owner will roll back the transaction.

## Return value

The **MsiJoinTransaction** function can return the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user that owns the transaction and the user that joins the transaction are not the same. |
| **ERROR_INVALID_PARAMETER** | A parameter that is not valid is passed to the function. |
| **ERROR_INSTALL_ALREADY_RUNNING** | The owner cannot be changed while an active installation is in progress. |
| **ERROR_INVALID_HANDLE_STATE** | The transaction ID provided is not valid. |

## Remarks

Because a transaction can be owned by no more than one process at a time, the functions authored into the [MsiEmbeddedChainer table](https://learn.microsoft.com/windows/desktop/Msi/msiembeddedchainer-table) can use **MsiJoinTransaction** to request ownership of the transaction before using the Windows Installer API to configure or install an application. The installer verifies that there is no installation in progress. The installer verifies that the process requesting ownership and the process that currently owns the transaction share a parent process in the same process tree. If the function succeeds, the process that calls **MsiJoinTransaction** becomes the current owner of the transaction.

**MsiJoinTransaction** sets the internal UI of the new installation to the UI level of the original installation. After the new installation owns the transaction, it can call [MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui) to change the UI level. This enables the new installation to run at a higher UI level than the original installation.

## See also

[Multiple Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)