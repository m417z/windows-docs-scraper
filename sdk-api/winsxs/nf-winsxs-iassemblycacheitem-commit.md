# IAssemblyCacheItem::Commit

## Description

The **Commit** method copies information into the side-by-side store. When this method returns, the assembly is visible in the side-by-side store.

## Parameters

### `dwFlags` [in]

This parameter specifies how existing information in the side-by-side store is to be replaced by information for the assembly being installed.

| Value | Meaning |
| --- | --- |
| **IASSEMBLYCACHEITEM_COMMIT_FLAG_REFRESH** | Replace existing information in the side-by-side store with the information in the assembly being installed if the version in the assembly is greater than or equal to the version of the existing information. This is the default option. |
| **IASSEMBLYCACHEITEM_COMMIT_FLAG_FORCE_REFRESH** | Replace existing information in the side-by-side store with the information for the assembly being installed. |

### `pulDisposition` [out, optional]

| Value | Meaning |
| --- | --- |
| **IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_INSTALLED** | The assembly is installed for the first time. |
| **IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_REFRESHED** | The assembly replaces an existing assembly. |
| **IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_ALREADY_INSTALLED** | The assembly is already installed in the side-by-side assembly store. |

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyCacheItem](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycacheitem)