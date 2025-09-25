# DlgDirListComboBoxA function

## Description

Replaces the contents of a combo box with the names of the subdirectories and files in a specified directory. You can filter the list of names by specifying a set of file attributes. The list of names can include mapped drive letters.

## Parameters

### `hDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the combo box.

### `lpPathSpec` [in, out]

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer containing a null-terminated string that specifies an absolute path, relative path, or file name. An absolute path can begin with a drive letter (for example, d:\\) or a UNC name (for example, \\*machinename*\*sharename*).

The function splits the string into a directory and a file name. The function searches the directory for names that match the file name. If the string does not specify a directory, the function searches the current directory.

If the string includes a file name, the file name must contain at least one wildcard character (? or *). If the string does not include a file name, the function behaves as if you had specified the asterisk wildcard character (*) as the file name. All names in the specified directory that match the file name and have the attributes specified by the *uFiletype* parameter are added to the list displayed in the combo box.

### `nIDComboBox` [in]

Type: **int**

The identifier of a combo box in the *hDlg* dialog box. If this parameter is zero, **DlgDirListComboBox** does not try to fill a combo box.

### `nIDStaticPath` [in]

Type: **int**

The identifier of a static control in the *hDlg* dialog box. **DlgDirListComboBox** sets the text of this control to display the current drive and directory. This parameter can be zero if you do not want to display the current drive and directory.

### `uFiletype` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of bit flags that specifies the attributes of the files or directories to be added to the combo box. This parameter can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **DDL_ARCHIVE** | Includes archived files. |
| **DDL_DIRECTORY** | Includes subdirectories, which are enclosed in square brackets ([ ]). |
| **DDL_DRIVES** | All mapped drives are added to the list. Drives are listed in the form [-*x*-], where *x* is the drive letter. |
| **DDL_EXCLUSIVE** | Includes only files with the specified attributes. By default, read/write files are listed even if DDL_READWRITE is not specified. |
| **DDL_HIDDEN** | Includes hidden files. |
| **DDL_READONLY** | Includes read-only files. |
| **DDL_READWRITE** | Includes read/write files with no additional attributes. This is the default setting. |
| **DDL_SYSTEM** | Includes system files. |
| **DDL_POSTMSGS** | If this flag is set, **DlgDirListComboBox** uses the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function to send messages to the combo box. If this flag is not set, **DlgDirListComboBox** uses the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function. |

## Return value

Type: **int**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. For example, if the string specified by *lpPathSpec* is not a valid path, the function fails. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If *lpPathSpec* specifies a directory, **DlgDirListComboBox** changes the current directory to the specified directory before filling the combo box. The text of the static control identified by the *nIDStaticPath* parameter is set to the name of the new current directory.

**DlgDirListComboBox** sends the [CB_RESETCONTENT](https://learn.microsoft.com/windows/desktop/Controls/cb-resetcontent) and [CB_DIR](https://learn.microsoft.com/windows/desktop/Controls/cb-dir) messages to the combo box.

Microsoft Windows NT 4.0 and later: If *uFiletype* includes the DDL_DIRECTORY flag and *lpPathSpec* specifies a first-level directory, such as C:\TEMP, the combo box will always include a ".." entry for the root directory. This is true even if the root directory has hidden or system attributes and the DDL_HIDDEN and DDL_SYSTEM flags are not specified. The root directory of an NTFS volume has hidden and system attributes.

**Security Warning:** Using this function incorrectly might compromise the security of your program. Incorrect use of this function includes having *lpPathSpec* indicate a non-writable buffer, or a buffer without a null-termination. You should review the [Security Considerations: Microsoft Windows Controls](https://learn.microsoft.com/windows/desktop/Controls/sec-comctls) before continuing.

Microsoft Windows NT 4.0 and later: The list displays long file names, if any.

Windows 95 or later: The list displays short file names (the 8.3 form). You can use the [SHGetFileInfo](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shgetfileinfoa) or [GetFullPathName](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfullpathnamea) functions to get the corresponding long file name.

Windows 95 or later: **DlgDirListComboBoxW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows Me/98/95 Systems](https://learn.microsoft.com/archive/msdn-magazine/2001/october/mslu-develop-unicode-applications-for-windows-9x-platforms-with-the-microsoft-layer-for-unicode).

> [!NOTE]
> The winuser.h header defines DlgDirListComboBox as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DlgDirList](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlista)

[DlgDirSelectComboBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirselectcomboboxexa)

**Reference**