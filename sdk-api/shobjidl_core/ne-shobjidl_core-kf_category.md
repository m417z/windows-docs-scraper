# KF_CATEGORY enumeration

## Description

Value that represent a category by which a folder registered with the Known Folder system can be classified.

## Constants

### `KF_CATEGORY_VIRTUAL:1`

Virtual folders are not part of the file system, which is to say that they have no path. For example, **Control Panel** and **Printers** are virtual folders. A number of features such as folder path and redirection do not apply to this category.

### `KF_CATEGORY_FIXED:2`

Fixed file system folders are not managed by the Shell and are usually given a permanent path when the system is installed. For example, the **Windows** and **Program Files** folders are fixed folders. A number of features such as redirection do not apply to this category.

### `KF_CATEGORY_COMMON:3`

Common folders are those file system folders used for sharing data and settings, accessible by all users of a system. For example, all users share a common **Documents** folder as well as their per-user **Documents** folder.

### `KF_CATEGORY_PERUSER:4`

Per-user folders are those stored under each user's profile and accessible only by that user. For example, `%USERPROFILE%\Pictures`. This category of folder usually supports many features including aliasing, redirection and customization.

**Note** The user profile root folder ([FOLDERID_Profile](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)) does not support redirection.

## Remarks

The **KF_CATEGORY** type is defined in Shobjidl.h as shown here.

```
typedef DWORD KF_CATEGORY;
```

## See also

[IKnownFolder::GetCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfolder-getcategory)

[KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))