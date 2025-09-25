# SetupInstallFromInfSectionW function

## Description

[This function is available for use in the operating systems indicated in the
Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used
for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI
continues to be used for installing device drivers.]

The **SetupInstallFromInfSection** function carries out all the directives in an
INF file **Install** section.

If the registry or file is modified, the caller of this function is required have privileges to write into the
system or target directory.

## Parameters

### `Owner`

Optional pointer to the window handle to the window that owns any dialog boxes that are generated during
installation, such as for disk prompting or file copying. If *Owner* is not specified,
these dialog boxes become top-level windows.

### `InfHandle`

Handle to the INF file that contains the section to be processed.

### `SectionName`

Name of the **Install** section in the INF file to process.

### `Flags`

Controls what actions to perform. The flags can be a combination of the following values.

#### SPINST_INIFILES

Perform INI-file operations (**UpdateInis**,
**UpdateIniFields** lines in the Install section being processed).

#### SPINST_REGISTRY

Perform registry operations (**AddReg**, **DelReg**
lines in the **Install** section being processed).

#### SPINST_INI2REG

Perform INI-file to registry operations (**Ini2Reg** lines in the **Install** section being
processed).

#### SPINST_LOGCONFIG

This flag is only used when installing a device driver.

Perform logical configuration operations (**LogConf** lines in the
**Install** section being processed). This flag is only used if
*DeviceInfoSet* and *DeviceInfoData* are specified.

For more information about installing device drivers, **LogConf**,
*DeviceInfoSet*, or *DeviceInfoData*, see the
DDK *Programmer's Guide*.

#### SPINST_FILES

Perform file operations (**CopyFiles**, **DelFiles**, **RenFiles** lines in the
**Install** section being processed).

#### SPINST_ALL

Perform all installation operations.

#### SPINST_REGISTERCALLBACKAWARE

When using the **RegisterDlls** INF directive to self-register DLLs
on Windows 2000, callers of **SetupInstallFromInfSection** may
receive notifications on each file as it is registered or unregistered. To send a
[SPFILENOTIFY_STARTREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-startregistration) or
[SPFILENOTIFY_ENDREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-endregistration)
notification to the callback routine, include SPINST_REGISTERCALLBACKAWARE plus either SPINST_REGSVR or
SPINST_UNREGSVR. The caller must also set the *MsgHandler* parameter.

#### SPINST_REGSVR

To send a notification to the callback routine when registering a file, include
SPINST_REGISTERCALLBACKAWARE plus SPINST_REGSVR in *Flags*. The caller must also
specify the *MsgHandler* parameter.

#### SPINST_UNREGSVR

To send a notification to the callback routine when unregistering a file, include
SPINST_REGISTERCALLBACKAWARE plus SPINST_UNREGSVR in the *Flags*. The caller must
also specify the *MsgHandler* parameter.

### `RelativeKeyRoot`

Optional parameter that must be specified if *Flags* includes SPINST_REGISTRY or
SPINST_INI2REG. Handle to a registry key to be used as the root when the INF file specifies HKR as the key.
Note that this parameter is ignored if **SetupInstallFromInfSection** is called
with the optional *DeviceInfoSet* and *DeviceInfoData* set.

### `SourceRootPath`

Source root for file copies. An example would be A:\ or \\pegasus\win\install. If
*Flags* includes SPINST_FILES, and *SourceRootPath* is NULL,
the system provides a default root path.

### `CopyFlags`

Optional parameter that must be specified if *Flags* includes SPINST_FILES.
Specifies flags to be passed to the
[SetupQueueCopySection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueuecopysectiona) function when files
are queued for copy. These flags may be a combination of the following values.

#### SP_COPY_DELETESOURCE

Delete the source file upon successful copy. The caller is not notified if the delete fails.

#### SP_COPY_REPLACEONLY

Copy the file only if doing so would overwrite a file at the destination path.

#### SP_COPY_NEWER_OR_SAME

Examine each file being copied to see if its version resources indicate that it is either the same
version or not newer than an existing copy on the target.

The file version information used during version checks is that specified in the
**dwFileVersionMS** and **dwFileVersionLS** members of a
[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure, as filled
in by the version functions. If one of the files does not have version resources, or if they have
identical version information, the source file is considered newer.

If the source file is not equal in version or newer, and *CopyMsgHandler* is
specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is
not specified, the file is not copied.

#### SP_COPY_NEWER_ONLY

Examine each file being copied to see if its version resources indicate that it is not newer than an
existing copy on the target. If the source file is newer but not equal in version to the existing target,
the file is copied.

#### SP_COPY_NOOVERWRITE

Check whether the target file exists, and, if so, notify the caller who may veto the copy. If
*CopyMsgHandler* is not specified, the file is not overwritten.

#### SP_COPY_NODECOMP

Do not decompress the file. When this flag is set, the target file is not given the uncompressed form
of the source name (if appropriate). For example, copying f:/x86\cmd.ex_ to
\\install\temp results in a target file of \\install\temp\cmd.ex_. If the
SP_COPY_NODECOMP flag was not specified, the file would be decompressed and the target would be called
\\install\temp\cmd.exe. The filename part of *DestinationName*, if
specified, is stripped and replaced with the filename of the source file. When SP_COPY_NODECOMP is
specified, no language or version information can be checked.

#### SP_COPY_LANGUAGEAWARE

Examine each file being copied to see if its language differs from the language of any existing file
already on the target. If so, and *CopyMsgHandler* is specified, the caller is
notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is
not copied.

#### SP_COPY_SOURCE_ABSOLUTE

*SourceFile* is a full source path. Do not look it up in the
**SourceDisksNames** section of the INF file.

#### SP_COPY_SOURCEPATH_ABSOLUTE

*SourcePathRoot* is the full path part of the source file. Ignore the relative
source specified in the **SourceDisksNames** section of the INF file for
the source media where the file is located. This flag is ignored if SP_COPY_SOURCE_ABSOLUTE is
specified.

#### SP_COPY_FORCE_IN_USE

If the target exists, behave as if it is in use and queue the file for copying on the next system
reboot.

#### SP_COPY_IN_USE_NEEDS_REBOOT

If the file was in use during the copy operation inform the user that the system needs to be rebooted.
This flag is only used when later calling
[SetupPromptReboot](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptreboot) or
[SetupScanFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupscanfilequeuea).

#### SP_COPY_NOSKIP

Do not give the user the option to skip a file.

#### SP_COPY_FORCE_NOOVERWRITE

Check whether the target file exists, and, if so, the file is not overwritten. The caller is not
notified.

#### SP_COPY_FORCE_NEWER

Examine each file being copied to see if its version resources (or time stamps for non-image files)
indicate that it is not newer than an existing copy on the target. If the file being copied is not newer,
the file is not copied. The caller is not notified.

#### SP_COPY_WARNIFSKIP

If the user tries to skip a file, warn them that skipping a file may affect the installation. (Used for
system-critical files.)

### `MsgHandler`

Pointer to the callback routine. The callback routine must be in the format of
[FileCallback](https://learn.microsoft.com/windows/desktop/api/setupapi/nc-setupapi-psp_file_callback_a). See
[Notifications](https://learn.microsoft.com/windows/desktop/SetupApi/notifications) for more information.

This parameter is optional only if the *Flags* parameter does not include
SPINST_FILES, SPINST_REGISTERCALLBACKAWARE plus SPINST_REGSVR, or SPINST_UNREGSVR.

*MsgHandler* must be set if *Flags* includes SPINST_FILES. In
this case, notification is sent to the callback routine when the file queue is committed with
[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea).

*MsgHandler* must be set if *Flags* includes
SPINST_REGISTERCALLBACKAWARE plus SPINST_REGSVR or SPINST_UNREGSVR. In this case a
[SPFILENOTIFY_STARTREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-startregistration)
or
[SPFILENOTIFY_ENDREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-endregistration)
is sent to the callback routine once each time a file is registered or unregistered using the
**RegisterDlls** INF directive on Windows 2000.

### `Context`

Value to be passed to the callback function when the file queue built by this routine internally is
committed via
[SetupCommitFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcommitfilequeuea). The
*Context* parameter is optional only if the *Flags* parameter
does not include SPINST_FILES. This parameter must be specified if *Flags* includes
SPINST_FILES.

### `DeviceInfoSet`

Optional pointer to a handle to a device information set. For more information about
the Device Installer setup functions, see the DDK
*Programmer's Guide*.

### `DeviceInfoData`

Optional pointer to a pointer to the **SP_DEVINFO_DATA**
structure that provides a context to a specific element in the set specified by
*DeviceInfoSet.* For more information about the Device Installer setup functions, see
the DDK *Programmer's Guide*.

##### - CopyFlags.SP_COPY_DELETESOURCE

Delete the source file upon successful copy. The caller is not notified if the delete fails.

##### - CopyFlags.SP_COPY_FORCE_IN_USE

If the target exists, behave as if it is in use and queue the file for copying on the next system
reboot.

##### - CopyFlags.SP_COPY_FORCE_NEWER

Examine each file being copied to see if its version resources (or time stamps for non-image files)
indicate that it is not newer than an existing copy on the target. If the file being copied is not newer,
the file is not copied. The caller is not notified.

##### - CopyFlags.SP_COPY_FORCE_NOOVERWRITE

Check whether the target file exists, and, if so, the file is not overwritten. The caller is not
notified.

##### - CopyFlags.SP_COPY_IN_USE_NEEDS_REBOOT

If the file was in use during the copy operation inform the user that the system needs to be rebooted.
This flag is only used when later calling
[SetupPromptReboot](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuppromptreboot) or
[SetupScanFileQueue](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupscanfilequeuea).

##### - CopyFlags.SP_COPY_LANGUAGEAWARE

Examine each file being copied to see if its language differs from the language of any existing file
already on the target. If so, and *CopyMsgHandler* is specified, the caller is
notified and may cancel the copy. If *CopyMsgHandler* is not specified, the file is
not copied.

##### - CopyFlags.SP_COPY_NEWER_ONLY

Examine each file being copied to see if its version resources indicate that it is not newer than an
existing copy on the target. If the source file is newer but not equal in version to the existing target,
the file is copied.

##### - CopyFlags.SP_COPY_NEWER_OR_SAME

Examine each file being copied to see if its version resources indicate that it is either the same
version or not newer than an existing copy on the target.

The file version information used during version checks is that specified in the
**dwFileVersionMS** and **dwFileVersionLS** members of a
[VS_FIXEDFILEINFO](https://learn.microsoft.com/windows/desktop/api/verrsrc/ns-verrsrc-vs_fixedfileinfo) structure, as filled
in by the version functions. If one of the files does not have version resources, or if they have
identical version information, the source file is considered newer.

If the source file is not equal in version or newer, and *CopyMsgHandler* is
specified, the caller is notified and may cancel the copy. If *CopyMsgHandler* is
not specified, the file is not copied.

##### - CopyFlags.SP_COPY_NODECOMP

Do not decompress the file. When this flag is set, the target file is not given the uncompressed form
of the source name (if appropriate). For example, copying f:/x86\cmd.ex_ to
\\install\temp results in a target file of \\install\temp\cmd.ex_. If the
SP_COPY_NODECOMP flag was not specified, the file would be decompressed and the target would be called
\\install\temp\cmd.exe. The filename part of *DestinationName*, if
specified, is stripped and replaced with the filename of the source file. When SP_COPY_NODECOMP is
specified, no language or version information can be checked.

##### - CopyFlags.SP_COPY_NOOVERWRITE

Check whether the target file exists, and, if so, notify the caller who may veto the copy. If
*CopyMsgHandler* is not specified, the file is not overwritten.

##### - CopyFlags.SP_COPY_NOSKIP

Do not give the user the option to skip a file.

##### - CopyFlags.SP_COPY_REPLACEONLY

Copy the file only if doing so would overwrite a file at the destination path.

##### - CopyFlags.SP_COPY_SOURCEPATH_ABSOLUTE

*SourcePathRoot* is the full path part of the source file. Ignore the relative
source specified in the **SourceDisksNames** section of the INF file for
the source media where the file is located. This flag is ignored if SP_COPY_SOURCE_ABSOLUTE is
specified.

##### - CopyFlags.SP_COPY_SOURCE_ABSOLUTE

*SourceFile* is a full source path. Do not look it up in the
**SourceDisksNames** section of the INF file.

##### - CopyFlags.SP_COPY_WARNIFSKIP

If the user tries to skip a file, warn them that skipping a file may affect the installation. (Used for
system-critical files.)

##### - Flags.SPINST_ALL

Perform all installation operations.

##### - Flags.SPINST_FILES

Perform file operations (**CopyFiles**, **DelFiles**, **RenFiles** lines in the
**Install** section being processed).

##### - Flags.SPINST_INI2REG

Perform INI-file to registry operations (**Ini2Reg** lines in the **Install** section being
processed).

##### - Flags.SPINST_INIFILES

Perform INI-file operations (**UpdateInis**,
**UpdateIniFields** lines in the Install section being processed).

##### - Flags.SPINST_LOGCONFIG

This flag is only used when installing a device driver.

Perform logical configuration operations (**LogConf** lines in the
**Install** section being processed). This flag is only used if
*DeviceInfoSet* and *DeviceInfoData* are specified.

For more information about installing device drivers, **LogConf**,
*DeviceInfoSet*, or *DeviceInfoData*, see the
DDK *Programmer's Guide*.

##### - Flags.SPINST_REGISTERCALLBACKAWARE

When using the **RegisterDlls** INF directive to self-register DLLs
on Windows 2000, callers of **SetupInstallFromInfSection** may
receive notifications on each file as it is registered or unregistered. To send a
[SPFILENOTIFY_STARTREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-startregistration) or
[SPFILENOTIFY_ENDREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-endregistration)
notification to the callback routine, include SPINST_REGISTERCALLBACKAWARE plus either SPINST_REGSVR or
SPINST_UNREGSVR. The caller must also set the *MsgHandler* parameter.

##### - Flags.SPINST_REGISTRY

Perform registry operations (**AddReg**, **DelReg**
lines in the **Install** section being processed).

##### - Flags.SPINST_REGSVR

To send a notification to the callback routine when registering a file, include
SPINST_REGISTERCALLBACKAWARE plus SPINST_REGSVR in *Flags*. The caller must also
specify the *MsgHandler* parameter.

##### - Flags.SPINST_UNREGSVR

To send a notification to the callback routine when unregistering a file, include
SPINST_REGISTERCALLBACKAWARE plus SPINST_UNREGSVR in the *Flags*. The caller must
also specify the *MsgHandler* parameter.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If a UNC directory is specified as the target directory of a file copy operation, you must ensure it exists
before you call **SetupInstallFromInfSection**. The setup functions do not check for
the existence of and do not create UNC directories. If the target UNC directory does not exist, the file
installation will fail.

This function requires a Windows INF file. Some older INF file formats may not be supported.

> [!NOTE]
> The setupapi.h header defines SetupInstallFromInfSection as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

**SetupInstallFromInfSection** will log diagnostic information to the [SetupAPI application installation text log](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi-text-logs). This log file is generally off by default. It can be enabled by modifying the *General logging levels* part of the SetupAPI `LogLevel` value as described at [Setting SetupAPI Logging Levels](https://learn.microsoft.com/windows-hardware/drivers/install/setting-setupapi-logging-levels). For performance reasons, you should only enable this log file when troubleshooting an issue. When the log file is enabled, you can find it at `%windir%\inf\setupapi.app.log`.

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SPFILENOTIFY_ENDREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-endregistration)

[SPFILENOTIFY_STARTREGISTRATION](https://learn.microsoft.com/windows/desktop/SetupApi/spfilenotify-startregistration)

[SetupInstallServicesFromInfSection](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinstallservicesfrominfsectiona)