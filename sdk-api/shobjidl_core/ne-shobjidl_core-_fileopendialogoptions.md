# _FILEOPENDIALOGOPTIONS enumeration

## Description

Defines the set of options available to an Open or Save dialog.

## Constants

### `FOS_OVERWRITEPROMPT:0x2`

When saving a file, prompt before overwriting an existing file of the same name. This is a default value for the Save dialog.

### `FOS_STRICTFILETYPES:0x4`

In the Save dialog, only allow the user to choose a file that has one of the file name extensions specified through [IFileDialog::SetFileTypes](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfiletypes).

### `FOS_NOCHANGEDIR:0x8`

Don't change the current working directory.

### `FOS_PICKFOLDERS:0x20`

Present an Open dialog that offers a choice of folders rather than files.

### `FOS_FORCEFILESYSTEM:0x40`

Ensures that returned items are file system items ([SFGAO_FILESYSTEM](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-getattributesof)). Note that this does not apply to items returned by [IFileDialog::GetCurrentSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getcurrentselection).

### `FOS_ALLNONSTORAGEITEMS:0x80`

Enables the user to choose any item in the Shell namespace, not just those with [SFGAO_STREAM](https://learn.microsoft.com/windows/desktop/shell/sfgao) or [SFAGO_FILESYSTEM](https://learn.microsoft.com/windows/desktop/shell/sfgao) attributes. This flag cannot be combined with FOS_FORCEFILESYSTEM.

### `FOS_NOVALIDATE:0x100`

Do not check for situations that would prevent an application from opening the selected file, such as sharing violations or access denied errors.

### `FOS_ALLOWMULTISELECT:0x200`

Enables the user to select multiple items in the open dialog. Note that when this flag is set, the [IFileOpenDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileopendialog) interface must be used to retrieve those items.

### `FOS_PATHMUSTEXIST:0x800`

The item returned must be in an existing folder. This is a default value.

### `FOS_FILEMUSTEXIST:0x1000`

The item returned must exist. This is a default value for the Open dialog.

### `FOS_CREATEPROMPT:0x2000`

Prompt for creation if the item returned in the open dialog does not exist. Note that this does not actually create the item.

### `FOS_SHAREAWARE:0x4000`

In the case of a sharing violation when an application is opening a file, call the application back through [OnShareViolation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-onshareviolation) for guidance. This flag is overridden by FOS_NOVALIDATE.

### `FOS_NOREADONLYRETURN:0x8000`

Do not return read-only items. This is a default value for the Save dialog.

### `FOS_NOTESTFILECREATE:0x10000`

Do not test whether creation of the item as specified in the Save dialog will be successful. If this flag is not set, the calling application must handle errors, such as denial of access, discovered when the item is created.

### `FOS_HIDEMRUPLACES:0x20000`

Hide the list of places from which the user has recently opened or saved items. This value is not supported as of Windows 7.

### `FOS_HIDEPINNEDPLACES:0x40000`

Hide items shown by default in the view's navigation pane. This flag is often used in conjunction with the [IFileDialog::AddPlace](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-addplace) method, to hide standard locations and replace them with custom locations.

**Windows 7 and later**. Hide all of the standard namespace locations (such as Favorites, Libraries, Computer, and Network) shown in the navigation pane.

**Windows Vista**. Hide the contents of the **Favorite Links** tree in the navigation pane. Note that the category itself is still displayed, but shown as empty.

### `FOS_NODEREFERENCELINKS:0x100000`

Shortcuts should not be treated as their target items. This allows an application to open a .lnk file rather than what that file is a shortcut to.

### `FOS_OKBUTTONNEEDSINTERACTION:0x200000`

The OK button will be disabled until the user navigates the view or edits the filename (if applicable). Note: Disabling of the OK button does not prevent the dialog from being submitted by the Enter key.

### `FOS_DONTADDTORECENT:0x2000000`

Do not add the item being opened or saved to the recent documents list ([SHAddToRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shaddtorecentdocs)).

### `FOS_FORCESHOWHIDDEN:0x10000000`

Include hidden and system items.

### `FOS_DEFAULTNOMINIMODE:0x20000000`

Indicates to the **Save As** dialog box that it should open in expanded mode. Expanded mode is the mode that is set and unset by clicking the button in the lower-left corner of the **Save As** dialog box that switches between **Browse Folders** and **Hide Folders** when clicked. This value is not supported as of Windows 7.

### `FOS_FORCEPREVIEWPANEON:0x40000000`

Indicates to the **Open** dialog box that the preview pane should always be displayed.

### `FOS_SUPPORTSTREAMABLEITEMS:0x80000000`

Indicates that the caller is opening a file as a stream ([BHID_Stream](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem-bindtohandler)), so there is no need to download that file.

## See also

[IFileDialog::GetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getoptions)

[IFileDialog::SetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setoptions)

[IFileSaveDialog::GetOptions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb775685(v=vs.85))

[IFileSaveDialog::SetOptions](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb775708(v=vs.85))