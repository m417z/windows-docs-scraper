# MsiEnumComponentCostsA function

## Description

The
**MsiEnumComponentCosts** function enumerates the disk-space per drive required to install a component. This information is needed to display the disk-space cost required for all drives in the user interface. The returned disk-space costs are expressed in multiples of 512 bytes.

**MsiEnumComponentCosts** should only be run after the installer has completed file costing and after the
[CostFinalize action](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action). For more information, see
[File Costing](https://learn.microsoft.com/windows/desktop/Msi/file-costing).

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szComponent` [in]

A null-terminated string specifying the component's name as it is listed in the Component column of the
[Component table](https://learn.microsoft.com/windows/desktop/Msi/component-table). This parameter can be null. If *szComponent* is null or an empty string,
**MsiEnumComponentCosts** enumerates the total disk-space per drive used during the installation. In this case, *iState* is ignored. The costs of the installer include those costs for caching the database in the secure folder as well as the cost to create the installation script. Note that the total disk-space used during the installation may be larger than the space used after the component is installed.

### `dwIndex` [in]

0-based index for drives. This parameter should be zero for the first call to the
**MsiEnumComponentCosts** function and then incremented for subsequent calls.

### `iState` [in]

Requested component state to be enumerated. If *szComponent* is passed as Null or an empty string, the installer ignores the *iState* parameter.

### `szDriveBuf` [out]

Buffer that holds the drive name including the null terminator. This is an empty string in case of an error.

### `pcchDriveBuf` [in, out]

Pointer to a variable that specifies the size, in TCHARs, of the buffer pointed to by the *lpDriveBuf* parameter. This size should include the terminating null character. If the buffer provided is too small, the variable pointed to by *pcchDriveBuf* contains the count of characters not including the null terminator.

### `piCost` [out]

Cost of the component per drive expressed in multiples of 512 bytes. This value is 0 if an error has occurred. The value returned in *piCost* is final disk-space used by the component after installation. If *szComponent* is passed as Null or an empty string, the installer sets the value at *piCost* to 0.

### `piTempCost` [out]

The component cost per drive for the duration of the installation, or 0 if an error occurred. The value in **piTempCost* represents the temporary space requirements for the duration of the installation. This temporary space requirement is space needed only for the duration of the installation. This does not affect the final disk space requirement.

## Return value

| Return Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE_STATE** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no more drives to return. |
| **ERROR_SUCCESS** | A value was enumerated. |
| **ERROR_UNKNOWN_COMPONENT** | The component is missing. |
| **ERROR_FUNCTION_NOT_CALLED** | Costing is not complete. |
| **ERROR_MORE_DATA** | Buffer not large enough for the drive name. |
| **ERROR_INVALID_HANDLE** | The supplied handle is invalid or inactive. |

## Remarks

The recommended method for enumerating the disk-space costs per drive is as follows. Start with the dwIndex set to 0 and increment it by one after each call. Continue the enumeration as long as
**MsiEnumComponentCosts** returns ERROR_SUCCESS.

**MsiEnumComponentCosts** may be called from custom actions.

The total final disk cost for the installation is the sum of the costs of all components plus the cost of the Windows Installer (*szComponent* = null).

> [!NOTE]
> The msiquery.h header defines MsiEnumComponentCosts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).