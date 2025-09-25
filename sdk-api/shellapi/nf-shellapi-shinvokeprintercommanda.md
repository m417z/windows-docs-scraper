# SHInvokePrinterCommandA function

## Description

Executes a command on a printer object.

**Note** This function has been deprecated as of Windows Vista. It is recommended that, in its place, you invoke verbs on printers through [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) or [ShellExecute](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shellexecutea).

## Parameters

### `hwnd` [in, optional]

Type: **HWND**

The handle of the parent window of any windows or dialog boxes that are created during the operation.

### `uAction`

Type: **UINT**

The type of printer operation to perform. One of the following values:

#### PRINTACTION_OPEN (0)

0x0. Open the printer specified by *lpBuf1*. The *lpBuf2* parameter is ignored.

#### PRINTACTION_PROPERTIES (1)

0x1. Display the property pages for the printer specified by *lpBuf1*. The *lpBuf2* parameter can be **NULL** or can name a specific property sheet to display, either by name or number. If the high **WORD** of *lpBuf2* is nonzero, it is assumed that this parameter is a pointer to a buffer that contains the name of the sheet to open. Otherwise, *lpBuf2* is seen as the zero-based index of the property sheet to open.

#### PRINTACTION_NETINSTALL (2)

0x2. Install the network printer specified by *lpBuf1*. The *lpBuf2* parameter is ignored.

#### PRINTACTION_NETINSTALLLINK (3)

0x3. Create a shortcut to the network printer specified by *lpBuf1*. The *lpBuf2* parameter specifies the drive and path of the folder in which to create the shortcut. The network printer must already have been installed on the local computer.

#### PRINTACTION_TESTPAGE (4)

0x4. Print a test page on the printer specified by *lpBuf1*. The *lpBuf2* parameter is ignored.

#### PRINTACTION_OPENNETPRN (5)

0x5. Open the network printer specified by *lpBuf1*. The *lpBuf2* parameter is ignored.

#### PRINTACTION_DOCUMENTDEFAULTS (6)

0x6. Display the default document properties for the printer specified by *lpBuf1*. The *lpBuf2* parameter is ignored.

#### PRINTACTION_SERVERPROPERTIES (7)

0x7. Display the properties for the printer server specified by *lpBuf1*. The *lpBuf2* parameter is ignored.

### `lpBuf1` [in]

Type: **LPCTSTR**

Pointer to a null-terminated string that contains additional information for the printer command. The information contained in this parameter depends upon the value of *uAction*.

### `lpBuf2` [in, optional]

Type: **LPCTSTR**

Pointer to a null-terminated string that contains additional information for the printer command. The information contained in this parameter depends upon the value of *uAction*.

### `fModal`

Type: **BOOL**

**TRUE** to specify that **SHInvokePrinterCommand** should not return until the command is completed; **FALSE** if the function should return as soon as the command is initialized.

## Return value

Type: **BOOL**

Returns **TRUE** if successful; otherwise, **FALSE**.

## Remarks

When a printer name is specified by *lpBuf1*, the name can either be the name of a local printer or the server and share name of a network printer. When specifying a network printer name, the name must be specified in this format:

```
"\\<server><shared printer name>"
```

This function is implemented in [Shell versions 4.71](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)) and later. In order to maintain backward compatibility with previous Shell versions, this function should not be used explicitly. Instead, the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions should be used to obtain the function address.

> [!NOTE]
> The shellapi.h header defines SHInvokePrinterCommand as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).