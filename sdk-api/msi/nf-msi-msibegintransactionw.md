# MsiBeginTransactionW function

## Description

The **MsiBeginTransaction** function starts [transaction processing](https://learn.microsoft.com/windows/desktop/Msi/t-gly) of a multiple-package installation and returns an identifier for the transaction. The [MsiEndTransaction](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiendtransaction) function ends the transaction.

**[Windows Installer 4.0 and earlier](https://learn.microsoft.com/windows/desktop/Msi/not-supported-in-windows-installer-4-0):** Not supported. This function is available beginning with Windows Installer 4.5.

## Parameters

### `szName` [in]

Name of the multiple-package installation.

### `dwTransactionAttributes` [in]

Attributes of the multiple-package installation.

| Value | Meaning |
| --- | --- |
| 0 | When 0 or no value is set it Windows Installer closes the UI from the previous installation. |
| MSITRANSACTION_CHAIN_EMBEDDEDUI | Set this attribute to request that the Windows Installer not shutdown the embedded UI until the transaction is complete. |

### `phTransactionHandle` [out]

Transaction ID is a **MSIHANDLE** value that identifies the transaction. Only one process can own a transaction at a time.

### `phChangeOfOwnerEvent` [out]

This parameter returns a handle to an event that is set when the [MsiJoinTransaction](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msijointransaction) function changes the owner of the transaction to a new owner. The current owner can use this to determine when ownership of the transaction has changed. Leaving a transaction without an owner will roll back the transaction.

## Return value

The **MsiBeginTransaction** function returns the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INSTALL_SERVICE_FAILURE** | The installation service could not be accessed. This function requires the Windows Installer service. |
| **ERROR_INSTALL_ALREADY_RUNNING** | Only one transaction can be open on a system at a time. The function returns this error if called while another transaction is running. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_ROLLBACK_DISABLED** | [Rollback Installations](https://learn.microsoft.com/windows/desktop/Msi/rollback-installation) have been disabled by the [DISABLEROLLBACK](https://learn.microsoft.com/windows/desktop/Msi/-disablerollback) property or [DisableRollback](https://learn.microsoft.com/windows/desktop/Msi/disablerollback) policy. |

## See also

[Multiple Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

## Remarks

> [!NOTE]
> The msi.h header defines MsiBeginTransaction as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).