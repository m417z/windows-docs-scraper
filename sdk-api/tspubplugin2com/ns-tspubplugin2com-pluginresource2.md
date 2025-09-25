# pluginResource2 structure

## Description

Contains additional information about a resource that can be assigned to users in RemoteApp and Desktop Connection.

## Members

### `resourceV1`

A [pluginResource](https://learn.microsoft.com/windows/win32/api/tspubplugincom/ns-tspubplugincom-pluginresource) structure that contains the basic information about the resource.

### `pceFileAssocListSize`

Reserved for future use. This member must be zero.

### `fileAssocList`

Reserved for future use. This member must be **NULL**.

### `securityDescriptor`

A string representation of a security descriptor used to specify the domain users and groups that have access to the resource. For more information about security descriptor strings, see [Security Descriptor String Format](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptor-string-format).

### `pceFolderListSize`

The number of strings in the **folderList** array.

### `folderList`

An array of pointers to null-terminated strings that contain the names of the folders that the resource should be displayed in. You must use the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function to allocate these strings. The caller is responsible for freeing these strings.

## Remarks

The **pluginFolderName** type is defined as follows:

`typedef [string] WCHAR* pluginFolderName;`

## See also

[GetResource2](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nf-tspubplugin2com-itspubplugin2-getresource2)

[GetResource2List](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nf-tspubplugin2com-itspubplugin2-getresource2list)

[pluginResource](https://learn.microsoft.com/windows/win32/api/tspubplugincom/ns-tspubplugincom-pluginresource)