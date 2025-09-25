# PROPPRG structure

## Description

This structure contains information from a .pif file. It is used by [PifMgr_GetProperties](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-pifmgr_getproperties).

## Members

### `flPrg`

Type: **WORD**

Flags that describe how the program will run.

#### PRG_DEFAULT

Use the default options.

#### PRG_CLOSEONEXIT

Close the application on exit.

### `flPrgInit`

Type: **WORD**

Flags that specify the initial conditions for the application.

#### PRGINIT_DEFAULT

Use the default options.

#### PRGINIT_MINIMIZED

The application should be minimized.

#### PRGINIT_MAXIMIZED

The application should be maximized.

#### PRGINIT_REALMODE

The application should run in real mode.

#### PRGINIT_REALMODESILENT

The application should run in real mode without being prompted.

#### PRGINIT_AMBIGUOUSPIF

The data is ambiguous.

#### PRGINIT_NOPIF

No .pif file was found.

#### PRGINIT_DEFAULTPIF

A default .pif was found.

#### PRGINIT_INFSETTINGS

A .inf file was found.

#### PRGINIT_INHIBITPIF

The .inf file indicates that a .pif file should not be created.

### `achTitle`

Type: **__wchar_t**

A null-terminated string that contains the title.

### `achCmdLine`

Type: **__wchar_t**

A null-terminated string that contains the command line, including arguments.

### `achWorkDir`

Type: **__wchar_t**

A null-terminated string that contains the working directory.

### `wHotKey`

Type: **WORD**

The key code of the .pif file's hotkey.

### `achIconFile`

Type: **__wchar_t**

A null-terminated string that contains the name of the file that contains the icon.

### `wIconIndex`

Type: **WORD**

The index of the icon in the file specified by **achIconFile**.

### `dwEnhModeFlags`

Type: **DWORD**

Reserved.

### `dwRealModeFlags`

Type: **DWORD**

Flags that specify the real mode options.

#### RMOPT_MOUSE

Requires a real-mode mouse.

#### RMOPT_EMS

Requires expanded memory.

#### RMOPT_CDROM

Requires CD-ROM support.

#### RMOPT_NETWORK

Requires network support.

#### RMOPT_DISKLOCK

Requires disk locking.

#### RMOPT_PRIVATECFG

Use a private config.sys or autoexec.bat file.

#### RMOPT_VESA

Requires a VESA driver.

### `achOtherFile`

Type: **__wchar_t**

A null-terminated string that contains the name of the "other" file in the directory.

### `achPIFFile`

Type: **__wchar_t**

A null-terminated string that contains the name of the .pif file in the directory.