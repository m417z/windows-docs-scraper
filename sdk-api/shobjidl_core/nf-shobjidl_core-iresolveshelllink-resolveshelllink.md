# IResolveShellLink::ResolveShellLink

## Description

Requests that a folder object resolve a Shell link.

## Parameters

### `punkLink` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

Pointer to the object's [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) interface. This interface can then be queried to determine the contents of the link.

### `hwnd` [in]

Type: **HWND**

Handle to the window that the Shell uses as the parent for a dialog box. The Shell displays the dialog box if it needs to prompt the user for more information while resolving the link.

### `fFlags` [in]

Type: **DWORD**

Action flags. This parameter can be a combination of the following values.

#### SLR_INVOKE_MSI

Call the Windows Installer.

#### SLR_NOLINKINFO

Disable distributed link tracking. By default, distributed link tracking tracks removable media across multiple devices based on the volume name. It also uses the UNC path to track remote file systems whose drive letter has changed. Setting **SLR_NOLINKINFO** disables both types of tracking.

#### SLR_NO_UI

Do not display a dialog box if the link cannot be resolved. When **SLR_NO_UI** is set, the high-order word of *fFlags* specifies a time-out duration, in milliseconds. The function returns if the link cannot be resolved within the time-out duration. If the high-order word is set to zero, the time-out duration defaults to 3000 milliseconds (3 seconds).

#### SLR_NOUPDATE

Do not update the link information.

#### SLR_NOSEARCH

Do not execute the search heuristics.

#### SLR_NOTRACK

Do not use distributed link tracking.

#### SLR_UPDATE

If the link object has changed, update its path and list of identifiers. If **SLR_UPDATE** is set, you do not need to call [IPersistFile::IsDirty](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-isdirty) to determine whether the link object has changed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method should attempt to find the target of a Shell link, even if the target has been moved or renamed.

## See also

[IResolveShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iresolveshelllink)