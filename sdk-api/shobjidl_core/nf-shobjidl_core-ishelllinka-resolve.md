# IShellLinkA::Resolve

## Description

Attempts to find the target of a Shell link, even if it has been moved or renamed.

## Parameters

### `hwnd`

Type: **HWND**

A handle to the window that the Shell will use as the parent for a dialog box. The Shell displays the dialog box if it needs to prompt the user for more information while resolving a Shell link.

### `fFlags`

Type: **DWORD**

Action flags. This parameter can be a combination of the following values.

#### SLR_NO_UI (0x0001)

0x0001. Do not display a dialog box if the link cannot be resolved. When **SLR_NO_UI** is set, the high-order word of *fFlags* can be set to a time-out value that specifies the maximum amount of time to be spent resolving the link. The function returns if the link cannot be resolved within the time-out duration. If the high-order word is set to zero, the time-out duration will be set to the default value of 3,000 milliseconds (3 seconds). To specify a value, set the high word of *fFlags* to the desired time-out duration, in milliseconds.

#### SLR_ANY_MATCH (0x0002)

0x0002. Not used.

#### SLR_UPDATE (0x0004)

0x0004. If the link object has changed, update its path and list of identifiers. If **SLR_UPDATE** is set, you do not need to call [IPersistFile::IsDirty](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-isdirty) to determine whether the link object has changed.

#### SLR_NOUPDATE (0x0008)

0x0008. Do not update the link information.

#### SLR_NOSEARCH (0x0010)

0x0010. Do not execute the search heuristics.

#### SLR_NOTRACK (0x0020)

0x0020. Do not use distributed link tracking.

#### SLR_NOLINKINFO (0x0040)

0x0040. Disable distributed link tracking. By default, distributed link tracking tracks removable media across multiple devices based on the volume name. It also uses the UNC path to track remote file systems whose drive letter has changed. Setting **SLR_NOLINKINFO** disables both types of tracking.

#### SLR_INVOKE_MSI (0x0080)

0x0080. Call the Windows Installer.

#### SLR_NO_UI_WITH_MSG_PUMP (0x0101)

0x0101. **Windows XP and later**.

#### SLR_OFFER_DELETE_WITHOUT_FILE (0x0200)

0x0200. **Windows 7 and later**. Offer the option to delete the shortcut when this method is unable to resolve it, even if the shortcut is not a shortcut to a file.

#### SLR_KNOWNFOLDER (0x0400)

0x0400. **Windows 7 and later**. Report as dirty if the target is a known folder and the known folder was redirected. This only works if the original target path was a file system path or ID list and not an aliased known folder ID list.

#### SLR_MACHINE_IN_LOCAL_TARGET (0x0800)

0x0800. **Windows 7 and later**. Resolve the computer name in UNC targets that point to a local computer. This value is used with [SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-shell_link_data_flags).

#### SLR_UPDATE_MACHINE_AND_SID (0x1000)

0x1000. **Windows 7 and later**. Update the computer GUID and user SID if necessary.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Following link creation, the name or location of the target may change. The **IShellLink::Resolve** method first retrieves the path associated with the link. If the object is no longer there or has been renamed, **Resolve** will attempt to find it. If successful, and the following conditions are met, the file that the link object was loaded from will be updated to reflect the new state of the link object.

* The **SLR_UPDATE** flag is set.
* The target has been moved or renamed, updating the internal state of the Shell link object to refer to the new target.
* The Shell link object was loaded from a file through [IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile).

The client can also call the [IPersistFile::IsDirty](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-isdirty) method to determine whether the link object has changed and the file needs to be updated.

**Resolve** has two approaches to finding target objects. The first is the distributed link tracking service. If the service is available, it can find an object that was on an NTFS version 5.0 volume and was moved to another location on that volume. It can also find an object that was moved to another NTFS version 5.0 volume, including volumes on other computers. To suppress the use of this service, set the **SLR_NOTRACK** flag.

If distributed link tracking is not available or fails to find the link object, **Resolve** attempts to find it with search heuristics. It first looks in the object's last known directory for an object with a different name but the same attributes and file creation time. Next, it recursively searches subdirectories in the vicinity of the object's last known directory. It looks for an object with the same name or creation time. Finally, **Resolve** looks for a matching object on the desktop and other local volumes. To suppress the use of the search heuristics, set the **SLR_NOSEARCH** flag.

If both approaches fail, the system will display a dialog box prompting the user for a location. To suppress the dialog box, set the **SLR_NO_UI** flag.