# SP_DRVINSTALL_PARAMS structure

## Description

An SP_DRVINSTALL_PARAMS structure contains driver installation parameters associated with a particular driver information element.

## Members

### `cbSize`

The size, in bytes, of the SP_DRVINSTALL_PARAMS structure.

### `Rank`

The rank match of this driver. Ranges from 0 to *n*, where 0 is the most compatible.

### `Flags`

Flags that control functions operating on this driver. Can be a combination of the following:

#### DNF_ALWAYSEXCLUDEFROMLIST (Windows Vista and later versions of Windows)

If set, this flag prevents the [driver node](https://learn.microsoft.com/windows-hardware/drivers/) from being enumerated, regardless of the client that is performing the enumeration.

#### DNF_AUTHENTICODE_SIGNED (Windows Server 2003 and later versions of Windows)

This driver's INF file is signed by an Authenticode signature. This flag is read-only to installers.

For more information, see [Using SetupAPI to Verify Driver Authenticode Signatures](https://learn.microsoft.com/windows-hardware/drivers/install/using-setupapi-to-verify-driver-authenticode-signatures).

#### DNF_BAD_DRIVER

Do not use this driver. Installers can read and write this flag.

If this flag is set, [SetupDiSelectBestCompatDrv](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiselectbestcompatdrv) and [SetupDiSelectDevice](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiselectdevice) ignore this driver.

A class installer or co-installer can set this flag to prevent Windows from listing the driver in the Select Driver dialog box. An installer might set this flag when it handles a [DIF_SELECTDEVICE](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectdevice) or [DIF_SELECTBESTCOMPATDRV](https://learn.microsoft.com/windows-hardware/drivers/install/dif-selectbestcompatdrv) request, for example.

#### DNF_BASIC_DRIVER (Windows XP and later versions of Windows)

This driver is a basic driver. This flag is read-only to installers.

#### DNF_CLASS_DRIVER

This driver is a class driver. This flag is read-only to installers.

#### DNF_COMPATIBLE_DRIVER

This driver is a compatible driver. This flag is read-only to installers.

#### DNF_DUPDESC

There are other providers supplying drivers that have the same description as this driver. This flag is read-only to installers.

#### DNF_DUPDRIVERVER (Windows XP and later versions of Windows)

There are other providers supplying drivers that have the same version as this driver. This flag is read-only to installers.

#### DNF_DUPPROVIDER

There are other providers supplying drivers that have the same description as this driver. The only difference between this driver and its match is the driver date. This flag is read-only to installers.

If this flag is set, Windows displays the driver date and driver version next to the driver so that the user can distinguish it from its match.

#### DNF_EXCLUDEFROMLIST

Do not display this driver in any driver-select dialogs.

#### DNF_INBOX_DRIVER (Windows Vista and later versions of Windows)

This [driver node](https://learn.microsoft.com/windows-hardware/drivers/) is derived from an INF file that was included with this version of Windows.

#### DNF_INET_DRIVER

This driver came from the Internet or from Windows Update. This flag is read-only to installers.

If you call [SetupCopyOEMInf](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupcopyoeminfa) you must specify the SPOST_URL flag so that when Windows copies this INF into the %*SystemRoot*%\*inf* directory Windows will mark it as an Internet INF. If you omit this step then Windows will attempt to use this device to install other devices. The resulting problem is that Windows does not have the source files any longer and will end up prompting the user with an invalid path.

#### DNF_INF_IS_SIGNED (Windows XP and later versions of Windows)

This flag is read-only to installers, and is set if any of the following conditions are true:

* The driver has a [WHQL release signature](https://learn.microsoft.com/windows-hardware/drivers/install/whql-release-signature).
* The driver is an inbox driver.
* The driver has an Authenticode signature.

For more information, see [Driver Signing](https://learn.microsoft.com/windows-hardware/drivers/install/driver-signing).

#### DNF_INSTALLEDDRIVER (Windows Vista and later versions of Windows)

This [driver node](https://learn.microsoft.com/windows-hardware/drivers/) is currently installed for the device. This flag is read-only to installers.

#### DNF_LEGACYINF

This driver comes from a legacy INF file. This flag is valid only for the NT-based operating system. This flag is read-only to installers.

#### DNF_NODRIVER

Set if no physical driver is to be installed for this logical driver.

#### DNF_OEM_F6_INF (Windows XP and later versions of Windows)

Reserved.

#### DNF_OLD_INET_DRIVER

This driver came from the Internet, but Windows does not currently have access to its source files. This flag is read-only to installers.

The system will not install a driver marked with this flag because Windows does not have the source files and would end up prompting the user with an invalid path. The INF for such a driver can be used for everything except for installing devices.

#### DNF_OLDDRIVER

This driver currently/previously controlled the associated device. This flag is read-only to installers.

#### DNF_REQUESTADDITIONALSOFTWARE (Windows 7 and later versions of Windows)

Set this flag if the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) is only part of the software solution that is needed to operate the device. In this case, the driver package requires the installation of additional software.

For more information, see the following Remarks section.

### `PrivateData`

A field a class installer can use to store private data. Co-installers should not use this field.

### `Reserved`

Reserved. For internal use only.

## Remarks

Starting with Windows 7, an installer or co-installer can set the DNF_REQUESTADDITIONALSOFTWARE flag to indicate that the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) requires additional software that may or not be installed in the computer.

After the [driver package](https://learn.microsoft.com/windows-hardware/drivers/install/difx-guidelines) for the device is installed, the Plug and Play (PnP) manager performs the following steps if the installer sets the DNF_REQUESTADDITIONALSOFTWARE flag:

1. The PnP manager generates a Problem Report and Solution (PRS) error report with the type of **RequestAddtionalSoftware**. This report contains information about the specific hardware ID of the device and the system architecture of the computer.
2. If there is a solution that is provided by the independent hardware vendor (IHV) for the device-specific software, the solution is downloaded to the computer.

   **Note** The download of the solution does not install the software itself.
3. If the device-specific software is not installed on the computer, the PnP manager presents the solution to the user and provides a link to download the software. The user can then choose to download and install this software by following the instructions presented in the solution.

**Note** The installer does not have to set the DNF_REQUESTADDITIONALSOFTWARE flag if the INF file for the [driver package](https://learn.microsoft.com/previous-versions/windows/hardware/difxapi/driverpackagepreinstall) has set the **RequestAdditionalSoftware**  flag in the [INF ControlFlags Section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-controlflags-section).

## See also

[SetupDiGetDriverInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetdriverinstallparamsa)

[SetupDiSetDriverInstallParams](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdisetdriverinstallparamsa)