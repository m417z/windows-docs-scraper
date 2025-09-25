# IMetaDataAssemblyImport::GetAssemblyProps

## Description

Gets the set of properties for the assembly with the specified metadata signature.

## Parameters

### `mda` [in]

The **mdAssembly** metadata token that represents the assembly for which to get the properties.

### `ppbPublicKey` [out]

A pointer to the public key or the metadata token.

### `pcbPublicKey` [out]

The number of bytes in the returned public key.

### `pulHashAlgId` [out]

A pointer to the algorithm used to hash the files in the assembly.

### `szName` [out]

The simple name of the assembly.

### `cchName` [in]

The size, in wide chars, of *szName*.

### `pchName` [out]

The number of wide chars actually returned in *szName*.

### `pMetaData` [out]

A pointer to an [ASSEMBLYMETADATA](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/assemblymetadata-structure) structure that contains the assembly metadata.

### `pdwAssemblyFlags` [out]

Flags that describe the metadata applied to an assembly. This value is a combination of one or more [CorAssemblyFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corassemblyflags-enumeration) values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)