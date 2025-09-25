# IAssemblyCache::CreateAssemblyCacheItem

## Description

The **CreateAssemblyCacheItem** method creates an item in the assembly cache that corresponds to the side-by-side assembly being installed.

## Parameters

### `dwFlags` [in]

Reserved.

### `pvReserved` [in]

Reserved.

### `ppAsmItem` [out]

Pointer to a location containing the pointer to the instance of the [IAssemblyCacheItem](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycacheitem) that receives the information.

### `pszAssemblyName` [in, optional]

Pointer to a null-terminated string value containing the fully-specified strong name of the assembly that is being installed. The name provided is verified to match the name of the assembly in the manifest. Partial names return **FUSION_E_INVALID_NAME**. If this parameter is null, the name is not verified.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |
| FUSION_E_INVALID_NAME | The full name of the assembly must be provided by *pszAssemblyName*. |

## See also

[IAssemblyCache](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycache)