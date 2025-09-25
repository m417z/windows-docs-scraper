# SHAddToRecentDocs function

## Description

Notifies the system that an item has been accessed, for the purposes of tracking those items used most recently and most frequently. This function can also be used to clear all usage data.

## Parameters

### `uFlags`

Type: **UINT**

A value from the [SHARD](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-shard) enumeration that indicates the form of the information pointed to by the *pv* parameter.

### `pv` [in, optional]

Type: **LPCVOID**

A pointer to data that identifies the item that has been accessed. The item can be specified in this parameter in one of the following forms:

* A null-terminated string that contains the path and file name of the item.
* A PIDL that identifies the item's file object.
* **Windows 7 and later only**. A [SHARDAPPIDINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfo), [SHARDAPPIDINFOIDLIST](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfoidlist), or [SHARDAPPIDINFOLINK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shardappidinfolink) structure that identifies the item through an AppUserModelID. See [Application User Model IDs (AppUserModelIDs)](https://learn.microsoft.com/windows/desktop/shell/appids) for more information.
* **Windows 7 and later only**. An [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) object that identifies the item through a shortcut.

Set this parameter to **NULL** to clear all usage data on all items.

## Remarks

The usage statistics gathered through calls to this method are used to determine lists of items accessed most recently and most frequently. These lists are seen in the **Start** menu and, in Windows 7 and later, in an application's Jump List.

When this method is called, it affects the following areas:

* Updates the **Recent** and **Frequent** lists for the associated application's Jump List.
* Adds a shortcut to the user's [Recent](https://learn.microsoft.com/windows/desktop/shell/manage) folder ([FOLDERID_Recent](https://learn.microsoft.com/windows/desktop/shell/knownfolderid), [CSIDL_RECENT](https://learn.microsoft.com/windows/desktop/shell/csidl)). This is reflected in the **My Recent Documents** (Windows XP) and **Recent Items** (Windows Vista and later) menu in the **Start** menu.
* Adds a shortcut to the Classic **Start** menu's **Documents** submenu. (Note that the Classic **Start** menu option is not available in Windows 7 and later.)

Items represented by an [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) are not added to the **Recent** folder, although they are reflected in an application's Jump List.

In some cases, notably when a user opens an item through Windows Explorer or uses the common file dialog to open, save, or create a file, the Shell calls **SHAddToRecentDocs** on behalf of the application. An application that has a custom UI for selecting items should call **SHAddToRecentDocs** explicitly to ensure accurate statistics. Duplicate calls are accounted for by the system so there is no risk of skewing the data by doing so.

Executable (.exe) files are filtered from the recently used documents list in Windows XP and later versions. Although **SHAddToRecentDocs** will accept the path of an executable file, that file will not appear in the **Recent Items** list.

Folders are also accepted by **SHAddToRecentDocs**, but appear only in the Jump List for the Windows Explorer taskbar button. Folders do not appear in any other application's Jump List.

In certain cases, **SHAddToRecentDocs** attempts to register an application to handle a file type that it is not registered to handle. This occurs under these circumstances:

* An application explicitly calls **SHAddToRecentDocs** with a file type that it is not registered to handle. This also applies to calls made to **SHAddToRecentDocs** by the common file dialog on behalf of the application, but only when the dialog is used to open a file, not when it is used to save one.
* The user drops a file of a type that the application is not registered to handle on the application's taskbar button.

This registration is done per-user.

A set of requirements must be met for the registration to be accomplished successfully:

* The application must be registered under **HKEY_CLASSES_ROOT**\**Applications**.
* That registration cannot include the NoOpenWith value. See [File Types](https://learn.microsoft.com/windows/desktop/shell/fa-file-types) for more details on NoOpenWith.
* That registration cannot supply data under a **SupportedTypes** subkey. See [File Types](https://learn.microsoft.com/windows/desktop/shell/fa-file-types) for more details on the **SupportedTypes** subkey.
* The application's executable file cannot be listed in the KillList value found here:

  ```
  HKEY_LOCAL_MACHINE
     Software
        Microsoft
           Windows
              CurrentVersion
                 Explorer
                    FileAssociation
                       KillList
  ```

  **Note** Third party applications should not modify the KillList value. It should be regarded as read-only.
* The application's **HKEY_CLASSES_ROOT**\**Applications** registration must have a set of default verbs defined under a
  **HKEY_CLASSES_ROOT**\**Applications**\*ExampleApp.exe*\**shell** subkey.

  If **SHAddToRecentDocs** is attempting the registration as the result of a drag-and-drop onto the taskbar button, the **shell** subkey is created if it does not already exist, as long as the existing application registration does not contain a NoOpenWith value and the application's executable is not listed in the KillList value.

### Suppressing Calls to SHAddToRecentDocs

In versions of Windows before Windows 7, a file type could set the [FTA_NoRecentDocs](https://learn.microsoft.com/windows/desktop/api/shlwapi/ne-shlwapi-filetypeattributeflags) flag to prevent that file type from being added to the **Recent** folder. This mechanism is also supported under Windows 7 and later. See [File Types](https://learn.microsoft.com/windows/desktop/shell/fa-file-types) for more information.

**SHAddToRecentDocs** tracks document usage statistics through the verbs that are invoked to access those documents. Verbs supplied by registered [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) handlers are tracked, those items appear in **My Recent Documents** (Windows XP) and **Recent Items** (Windows Vista). In Windows 7, the parent folders of the documents appear in the Jump List for the Windows Explorer taskbar button. However, the documents accessed through those **IContextMenu** verbs do not appear in application Jump Lists. For those items to appear in an application's Jump List, an application must call **SHAddToRecentDocs** explicitly.

Prior to Windows 7, only the `open` verb resulted in a call to **SHAddToRecentDocs**. In Windows 7 and later, other verbs can also generate usage statistics. This information is used to make a Jump List's destinations more complete and accurate.

However, some classes of file type association registrations or individual [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) implementations are not appropriate for this sort of tracking. The point of usage tracking is to generate a list of items that the user is likely to want to access again. If a particular verb—`delete`, for instance—is inherently invoked on an item that the user will not access again, or is a secondary action such as a virus scan on a file, that verb is not appropriate for tracking. File type classes should remove themselves from this tracking through the registry entry NoRecentDocs. NoRecentDocs is of type REG_SZ and has no associated data. Its presence is all that is required to prevent the call to **SHAddToRecentDocs**.

For example, context menu extensions and static verbs registered under **HKEY_CLASSES_ROOT** in classes such as "*", "AllFileSystemObjects", or "Folder" should not be tracked. In cases such as these, the NoRecentDocs entry is added to the root of the class key as shown here to suppress tracking of documents launched through any verb or extension registered to that class:

```
HKEY_CLASSES_ROOT
   AllFileSystemObjects
      NoRecentDocs
```

The NoRecentDocs entry is assigned by default to the *****, **AllFileSystemObjects**, **Folder**, **Directory**, and **DesktopBackground** class subkeys.

Individual [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) implementations can opt out of tracking by adding a NoRecentDocs subkey to its Component Object Model (COM) object's registration, in its **shellex** subkey, as shown here:

```
HKEY_CLASSES_ROOT
   CLSID
      {093C7AAB-5E72-454f-A91D-CA1BC991FCEC}
         shellex
            NoRecentDocs
```

This subkey is not present by default on any [IContextMenu](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icontextmenu) implementation.

## See also

[SHGetFolderLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderlocation)

[SHGetFolderPath](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetfolderpatha)