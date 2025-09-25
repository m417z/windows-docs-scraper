# IFileOperation::SetOperationFlags

## Description

Sets parameters for the current operation.

## Parameters

### `dwOperationFlags` [in]

Type: **DWORD**

Flags that control the file operation. This member can be a combination of the following flags. FOF flags are defined in Shellapi.h and FOFX flags are defined in Shobjidl.h.

**Note** If this method is not called, the default value used by the operation is FOF_ALLOWUNDO | FOF_NOCONFIRMMKDIR.

#### FOF_ALLOWUNDO (0x0040)

Preserve undo information, if possible.

Prior to Windows Vista, operations could be undone only from the same process that performed the original operation.

In Windows Vista and later systems, the scope of the undo is a user session. Any process running in the user session can undo another operation. The undo state is held in the Explorer.exe process, and as long as that process is running, it can coordinate the undo functions.

If the source file parameter does not contain fully qualified path and file names, this flag is ignored.

#### FOF_FILESONLY (0x0080)

Perform the operation only on files (not on folders) if a wildcard file name (*.*) is specified.

#### FOF_NOCONFIRMATION (0x0010)

Respond with **Yes to All** for any dialog box that is displayed.

#### FOF_NOCONFIRMMKDIR (0x0200)

Do not confirm the creation of a new folder if the operation requires one to be created.

#### FOF_NO_CONNECTED_ELEMENTS (0x2000)

Do not move connected items as a group. Only move the specified files.

#### FOF_NOCOPYSECURITYATTRIBS (0x0800)

Do not copy the security attributes of the item.

#### FOF_NOERRORUI (0x0400)

Do not display a message to the user if an error occurs. If this flag is set without FOFX_EARLYFAILURE, any error is treated as if the user had chosen **Ignore** or **Continue** in a dialog box. It halts the current action, sets a flag to indicate that an action was aborted, and proceeds with the rest of the operation.

#### FOF_NORECURSION (0x1000)

Only operate in the local folder. Do not operate recursively into subdirectories.

#### FOF_RENAMEONCOLLISION (0x0008)

Give the item being operated on a new name in a move, copy, or rename operation if an item with the target name already exists.

#### FOF_SILENT (0x0004)

Do not display a progress dialog box.

#### FOF_WANTNUKEWARNING (0x4000)

Send a warning if a file or folder is being destroyed during a delete operation rather than recycled. This flag partially overrides **FOF_NOCONFIRMATION**.

#### FOFX_ADDUNDORECORD (0x20000000)

**Introduced in Windows 8**. The file operation was user-invoked and should be placed on the undo stack. This flag is preferred to FOF_ALLOWUNDO.

#### FOFX_NOSKIPJUNCTIONS (0x00010000)

Walk into Shell namespace junctions. By default, junctions are not entered. For more information on junctions, see [Specifying a Namespace Extension's Location](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/cc144096(v=vs.85)).

#### FOFX_PREFERHARDLINK (0x00020000)

If possible, create a hard link rather than a new instance of the file in the destination.

#### FOFX_SHOWELEVATIONPROMPT (0x00040000)

If an operation requires elevated rights and the FOF_NOERRORUI flag is set to disable error UI, display a UAC UI prompt nonetheless.

#### FOFX_EARLYFAILURE (0x00100000)

If FOFX_EARLYFAILURE is set together with FOF_NOERRORUI, the entire set of operations is stopped upon encountering any error in any operation. This flag is valid only when FOF_NOERRORUI is set.

#### FOFX_PRESERVEFILEEXTENSIONS (0x00200000)

Rename collisions in such a way as to preserve file name extensions. This flag is valid only when FOF_RENAMEONCOLLISION is also set.

#### FOFX_KEEPNEWERFILE (0x00400000)

Keep the newer file or folder, based on the Date Modified property, if a collision occurs. This is done automatically with no prompt UI presented to the user.

#### FOFX_NOCOPYHOOKS (0x00800000)

Do not use copy hooks.

#### FOFX_NOMINIMIZEBOX (0x01000000)

Do not allow the progress dialog to be minimized.

#### FOFX_MOVEACLSACROSSVOLUMES (0x02000000)

Copy the security attributes of the source item to the destination item when performing a cross-volume move operation. Without this flag, the destination item receives the security attributes of its new folder.

#### FOFX_DONTDISPLAYSOURCEPATH (0x04000000)

Do not display the path of the source item in the progress dialog.

#### FOFX_DONTDISPLAYDESTPATH (0x08000000)

Do not display the path of the destination item in the progress dialog.

#### FOFX_RECYCLEONDELETE (0x00080000)

**Introduced in Windows 8**. When a file is deleted, send it to the Recycle Bin rather than permanently deleting it.

#### FOFX_REQUIREELEVATION (0x10000000)

**Introduced in Windows Vista SP1**. The user expects a requirement for rights elevation, so do not display a dialog box asking for a confirmation of the elevation.

#### FOFX_COPYASDOWNLOAD (0x40000000)

**Introduced in Windows 7**. Display a **Downloading** instead of **Copying** message in the progress dialog.

#### FOFX_DONTDISPLAYLOCATIONS (0x80000000)

**Introduced in Windows 7**. Do not display the location line in the progress dialog.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Set these flags before you call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to define the parameters for whatever operations are being performed, such as copy, delete, or rename.