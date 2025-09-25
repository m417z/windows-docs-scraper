# IKnownFolder::GetFolderDefinition

## Description

Retrieves a structure that contains the defining elements of a known folder, which includes the folder's category, name, path, description, tooltip, icon, and other properties.

## Parameters

### `pKFD` [out]

Type: **[KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition)***

When this method returns, contains a pointer to the [KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition) structure. When no longer needed, the calling application is responsible for calling [FreeKnownFolderDefinitionFields](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-freeknownfolderdefinitionfields) to free this resource.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a third-party application creates their own known folder, they do so by defining it with a [KNOWNFOLDER_DEFINITION](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-knownfolder_definition) structure, then registering it with the system. Any registered known folder definition information—system-provided or application-created—can be retrieved through this method.

To call this method, the caller must have at least User privileges.

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))