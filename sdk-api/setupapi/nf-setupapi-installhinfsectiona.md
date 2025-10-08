# InstallHinfSectionA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

**InstallHinfSection** is an entry-point function exported by Setupapi.dll that you can use to execute a section of an .inf file.

> [!NOTE]
> For many scenarios, it is recommended that you use a [primitive driver package](https://learn.microsoft.com/windows-hardware/drivers/develop/creating-a-primitive-driver) instead of using a .inf file with InstallHinfSection

**InstallHinfSection** can be invoked by calling the Rundll32.exe utility as described in the Remarks section. The prototype for the **InstallHinfSection** function follows the form of all entry-point functions used with Rundll32.exe.

If a file is copied or modified, the caller of this function is required have privileges to write into the target directory. If there are any services being installed, the caller of this function is required have access to the
[Service Control Manager](https://learn.microsoft.com/windows/desktop/Services/service-control-manager).

## Parameters

### `Window` [in]

The parent window handle. Typically *hwnd* is Null.

### `ModuleHandle` [in]

Reserved and should be Null.

### `CommandLine` [in]

Pointer to buffer containing the command line. You should use a null-terminated string.

### `ShowCommand` [in]

Reserved and should be zero.

## Remarks

Note that three exports exist:
**InstallHinfSection** (for RunDll32), **InstallHinfSectionA**, and **InstallHinfSectionW**.

To run an **Install** section of a specified .inf file, you can invoke
**InstallHinfSection** with the Rundll32.exe by using the following syntax.

```cmd
RUNDLL32.EXE SETUPAPI.DLL,InstallHinfSection <section> <mode> <path>
```

This passes "*\<section>* *\<mode>* *\<path>*" to *CmdLineBuffer*.

Alternatively, your program may call
**InstallHinfSection**, **InstallHinfSectionA**, or **InstallHinfSectionW** directly, setting the *CmdLineBuffer* parameter to the following.

``` syntax
"<section> <mode> <path>"
```

Where *path* is the full path to the .inf file, *mode* is the reboot mode parameter, and *section* is any **Install** section in the .inf file. The comma separator between SETUPAPI.DLL and
**InstallHinfSection** on the command line is required. Note that there cannot be any white space on the command line between the comma and SETUPAPI.DLL or
**InstallHinfSection**.

It is recommended that you specify the full path to the .inf file as *path*.

You may specify any **Install** section in the .inf file as *section*. No spaces are allowed.

You should use a combination of the following values for *mode*. You must include 128 to set the default path of the installation to the location of the INF, otherwise a system-provided INF is assumed. Add values to specify rebooting. Note that only the values 128 or 132 are recommended, other values may cause the computer to reboot unnecessarily or not reboot when it required.

| Value | Description |
| --- | --- |
| 0 | System provided INF. |
| 128 | Set the default path of the installation to the location of the INF. This is the typical setting. |
| +0 | Never reboot the computer. |
| +1 | Reboot the computer in all cases. |
| +2 | Always ask the users if they want to reboot. |
| +3 | Reboot the computer if necessary without asking user for permission. |
| +4 | If a reboot of the computer is necessary, ask the user for permission before rebooting. |

For example, the following command line runs the DefaultInstall section of the Shell.inf file. If Setup determines a reboot is required, the user is will be prompted with a "Reboot the computer, Yes/No" dialog box.

```cmd
RUNDLL32.EXE SETUPAPI.DLL,InstallHinfSection DefaultInstall 132 C:\Example\SHELL.INF
```

> [!NOTE]
> The setupapi.h header defines InstallHinfSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

> [!CAUTION]
> When used on an architecture other than x86 or amd64, or when used on a system in [S mode](https://learn.microsoft.com/windows-hardware/manufacture/desktop/windows-10-s-overview), InstallHInfSection requires that the INF file have a [INF Version section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-version-section) with a CatalogFile directive that points at a signed catalog file that contains the hash of the INF file and any files the INF file references via a [INF SourceDisksFiles section](https://learn.microsoft.com/windows-hardware/drivers/install/inf-sourcedisksfiles-section).

> [!CAUTION]
> When used on a system whose native architecture is not x86 nor amd64, InstallHInfSection should be used from a native architecture process. InstallHInfSection will block many types of system state changing operations when used from a non-native architecture process.

**InstallHinfSection** will log diagnostic information to the [SetupAPI application installation text log](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs). This log file is generally off by default. It can be enabled by modifying the *General logging levels* part of the SetupAPI `LogLevel` value as described at [Setting SetupAPI Logging Levels](https://learn.microsoft.com/windows-hardware/drivers/install/setting-setupapi-logging-levels). For performance reasons, you should only enable this log file when troubleshooting an issue. When the log file is enabled, you can find it at `%windir%\inf\setupapi.app.log`.