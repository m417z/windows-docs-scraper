# IAssemblyCache::QueryAssemblyInfo

## Description

The **QueryAssemblyInfo** method queries the side-by-side assembly store for assembly information and validates the files in the side-by-side assembly store against the assembly manifest.

## Parameters

### `dwFlags` [in, optional]

Specifies the information to retrieve.

This parameter can be one or more of the following values or 0.

| Value | Meaning |
| --- | --- |
| **QUERYASMINFO_FLAG_VALIDATE** | Validates the assembly files in the side-by-side assembly store against the assembly manifest. This includes the verification of the assembly's hash and strong name signature. |
| **QUERYASMINFO_FLAG_GETSIZE** | Returns the size of all files in the assembly. |

### `pszAssemblyName` [in]

Pointer to null-terminated string value containing the fully-specified strong name of the assembly to query. If the name is not fully specified, the result of the method is undefined.

### `pAsmInfo` [in, out]

Pointer to the [ASSEMBLY_INFO](https://learn.microsoft.com/windows/desktop/api/winsxs/ns-winsxs-assembly_info) structure that receives the information.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyCache](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycache)