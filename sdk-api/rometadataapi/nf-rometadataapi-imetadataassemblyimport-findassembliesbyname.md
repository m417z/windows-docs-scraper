# IMetaDataAssemblyImport::FindAssembliesByName

## Description

Gets an array of assemblies with the specified name, using the standard rules employed by the common language runtime (CLR) for resolving references.

## Parameters

### `szAppBase` [in]

The root directory in which to search for the given assembly. If this value is set to null, **FindAssembliesByName** will look only in the global assembly cache for the assembly.

### `szPrivateBin` [in]

A list of semicolon-delimited subdirectories (for example, "bin;bin2"), under the root directory, in which to search for the assembly. These directories are probed in addition to those specified in the default probing rules.

### `szAssemblyName` [in]

The name of the assembly to find. The format of this string is defined in the class reference page for [AssemblyName](https://learn.microsoft.com/dotnet/api/system.reflection.assemblyname).

### `ppIUnk` [out]

An array of type IUnknown in which to put the [IMetadataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport) interface pointers.

### `cMax` [in]

The maximum number of interface pointers that can be placed in *ppIUnk*.

### `pcAssemblies` [out]

The number of interface pointers returned. That is, the number of interface pointers actually placed in *ppIUnk*.

## Return value

| HRESULT | Description |
| --- | --- |
| **S_OK** | **FindAssembliesByName** returned successfully. |
| **S_FALSE** | There are no assemblies. |

## Remarks

Given an assembly name, the **FindAssembliesByName** method finds the assembly by following the standard rules for resolving assembly references. **FindAssembliesByName** allows the caller to configure various aspects of the assembly resolver context, such as application base and private search path.

**FindAssembliesByName** returns an [IMetaDataImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataimport) pointer to the file containing the assembly manifest for the assembly name that is passed in. If the given assembly name is not fully specified (for example, if it does not include a version), multiple assemblies might be returned.

**FindAssembliesByName** is commonly used by a compiler that attempts to find a referenced assembly at compile time.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)