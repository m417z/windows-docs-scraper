# IMetaDataAssemblyImport::GetAssemblyRefProps

## Description

Gets the set of properties for the assembly reference with the specified metadata signature.

## Parameters

### `mdar` [in]

The **mdAssemblyRef** metadata token that represents the assembly reference for which to get the properties.

### `ppbPublicKeyOrToken` [out]

A pointer to the public key or the metadata token.

### `pcbPublicKeyOrToken` [out]

The number of bytes in the returned public key or token.

### `szName` [out]

The simple name of the assembly.

### `cchName` [in]

The size, in wide chars, of *szName*.

### `pchName` [out]

A pointer to the number of wide chars actually returned in *szName*.

### `pMetaData` [out]

A pointer to an [ASSEMBLYMETADATA](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/assemblymetadata-structure) structure that contains the assembly metadata.

### `ppbHashValue` [out]

A pointer to the hash value. This is the hash, using the SHA-1 algorithm, of the PublicKey property of the assembly being referenced, unless the arfFullOriginator flag of the [AssemblyRefFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/assemblyrefflags-enumeration) enumeration is set.

### `pcbHashValue` [out]

The number of wide chars in the returned hash value.

### `pdwAssemblyRefFlags` [out]

 A pointer to flags that describe the metadata applied to an assembly. The flags value is a combination of one or more [CorAssemblyFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/corassemblyflags-enumeration) values.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataAssemblyImport](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadataassemblyimport)