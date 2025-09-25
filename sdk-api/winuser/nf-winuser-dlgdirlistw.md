# DlgDirListW function

## Description

Replaces the contents of a list box with the names of the subdirectories and files in a specified directory. You can filter the list of names by specifying a set of file attributes. The list can optionally include mapped drives.

## Parameters

### `hDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the list box.

### `lpPathSpec` [in, out]

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer containing a null-terminated string that specifies an absolute path, relative path, or filename. An absolute path can begin with a drive letter (for example, d:\) or a UNC name (for example, \\
*machinename*\
*sharename*).

The function splits the string into a directory and a filename. The function searches the directory for names that match the filename. If the string does not specify a directory, the function searches the current directory.

If the string includes a filename, the filename must contain at least one wildcard character (? or *). If the string does not include a filename, the function behaves as if you had specified the asterisk wildcard character (*) as the filename. All names in the specified directory that match the filename and have the attributes specified by the
*uFileType* parameter are added to the list box.

### `nIDListBox` [in]

Type: **int**

The identifier of a list box in the
*hDlg* dialog box. If this parameter is zero, **DlgDirList** does not try to fill a list box.

### `nIDStaticPath` [in]

Type: **int**

The identifier of a static control in the
*hDlg* dialog box. **DlgDirList** sets the text of this control to display the current drive and directory. This parameter can be zero if you do not want to display the current drive and directory.

### `uFileType` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the attributes of the files or directories to be added to the list box. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **DDL_ARCHIVE** | Includes archived files. |
| **DDL_DIRECTORY** | Includes subdirectories. Subdirectory names are enclosed in square brackets ([ ]). |
| **DDL_DRIVES** | All mapped drives are added to the list. Drives are listed in the form [- *x*-], where *x* is the drive letter. |
| **DDL_EXCLUSIVE** | Includes only files with the specified attributes. By default, read/write files are listed even if DDL_READWRITE is not specified. |
| **DDL_HIDDEN** | Includes hidden files. |
| **DDL_READONLY** | Includes read-only files. |
| **DDL_READWRITE** | Includes read/write files with no additional attributes. This is the default setting. |
| **DDL_SYSTEM** | Includes system files. |
| **DDL_POSTMSGS** | If set, **DlgDirList** uses the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function to send messages to the list box. If not set, **DlgDirList** uses the [SendMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendmessage) function. |

## Return value

Type: **int**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. For example, if the string specified by
*lpPathSpec* is not a valid path, the function fails. To get extended error information, call .

## Remarks

If
*lpPathSpec* specifies a directory, [DlgDirListComboBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlistcomboboxa) changes the current directory to the specified directory before filling the list box. The text of the static control identified by the
*nIDStaticPath* parameter is set to the name of the new current directory.

**DlgDirList** sends the
[LB_RESETCONTENT](https://learn.microsoft.com/windows/desktop/Controls/lb-resetcontent) and
[LB_DIR](https://learn.microsoft.com/windows/desktop/Controls/lb-dir) messages to the list box.

If
*uFileType* includes the DDL_DIRECTORY flag and
*lpPathSpec* specifies a first-level directory, such as C:\TEMP, the list box will always include a ".." entry for the root directory. This is true even if the root directory has hidden or system attributes and the DDL_HIDDEN and DDL_SYSTEM flags are not specified. The root directory of an NTFS volume has hidden and system attributes.

The directory listing displays long filenames, if any.

#### Examples

For examples, see the following topics: [Creating a Directory Listing in a Single-selection List Box](https://learn.microsoft.com/windows/desktop/Controls/using-list-boxes) and [Creating a Multiple-selection List Box](https://learn.microsoft.com/windows/desktop/Controls/using-list-boxes).

> [!NOTE]
> The winuser.h header defines DlgDirList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DlgDirListComboBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlistcomboboxa)

[DlgDirSelectComboBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirselectcomboboxexa)

[DlgDirSelectEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirselectexa)

**Reference**