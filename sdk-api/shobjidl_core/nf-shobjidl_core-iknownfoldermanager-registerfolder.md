# IKnownFolderManager::RegisterFolder

## Description

Adds a new known folder to the registry. Used particularly by independent software vendors (ISVs) that are adding one of their own folders to the known folder system.

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

A **GUID** that represents the known folder.

### `pKFD` [in]

Type: **const KNOWNFOLDER_DEFINITION***

A pointer to a valid [KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition) structure that provides the details of the new folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** This method updates **HKEY_LOCAL_MACHINE** and therefore needs to be run in the context of an administrator. Setup programs need administrator privileges to register or unregister a known folder.

**IKnownFolderManager::RegisterFolder** attempts to verify that the new [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) does not refer to a file system path already pointed to by an existing **KNOWNFOLDERID**. If the new **KNOWNFOLDERID** is found to do so, this method fails.

Multiple [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) values for the same file system path can cause several issues, such as conflicts in the Desktop.ini file that lead to confusion as to what language or properties to show for the folder. Multiple **KNOWNFOLDERID** values can also cause confusion as to the address bar path or what tasks to show for the folder in Windows Explorer.

You can suppress the display of the **Customize** page of your known folder's Properties window. To do so, set the following registry REG_DWORD value:

```
HKEY_LOCAL_MACHINE
   Software
      Microsoft
         Windows
            CurrentVersion
               Explorer
                  FolderDescriptions
                     Folder GUID
                        PropertyBag
                           NoCustomize = 0x00000001 (1)
```

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[IKnownFolderManager::UnregisterFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-unregisterfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))