# ASSEMBLY_INFO structure

## Description

The **ASSEMBLY_INFO** structure contains information about an assembly in the side-by-side assembly store. The information is used by the [QueryAssemblyInfo](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblycache-queryassemblyinfo) method.

## Members

### `cbAssemblyInfo`

The size of the structure in bytes.

### `dwAssemblyFlags`

 This member can contain the following values:

| Value | Meaning |
| --- | --- |
| **ASSEMBLYINFO_FLAG_INSTALLED** | Set this flag when using Windows Vista and later or Windows Server 2008 and later with the assembly installed in the side-by-side assembly store. |

### `uliAssemblySizeInKB`

The size of the files that comprise the assembly in kilobytes (KB).

### `pszCurrentAssemblyPathBuf`

A pointer to a null-terminated string that contains the path to the manifest file.

### `cchBuf`

The number of characters, including the null terminator, in the string specified by *pszCurrentAssemblyPathBuf*.