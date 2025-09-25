# IMetaDataDispenser::OpenScopeOnMemory

## Description

Opens an area of memory that contains existing metadata. That is, this method opens a specified area of memory in which the existing data is treated as metadata.

## Parameters

### `pData` [in]

A pointer that specifies the starting address of the memory area.

### `cbData` [in]

The size of the memory area, in bytes.

### `dwOpenFlags` [in]

A value of the [CorOpenFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/coropenflags-enumeration) enumeration to specify the mode (read, write, and so on) for opening.

### `riid` [in]

The IID of the desired metadata interface to be returned; the caller will use the interface to import (read) or emit (write) metadata.

The value of riid must specify one of the "import" or "emit" interfaces. Valid values are **IID_IMetaDataEmit**, **IID_IMetaDataImport**, **IID_IMetaDataAssemblyEmit**, **IID_IMetaDataAssemblyImport**, **IID_IMetaDataEmit2**, or **IID_IMetaDataImport2**.

### `ppIUnk` [out]

The pointer to the returned interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The in-memory copy of the metadata can be queried using methods from one of the "import" interfaces, or added to using methods from the one of the "emit" interfaces.

The **OpenScopeOnMemory** method is similar to the [OpenScope](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nf-rometadataapi-imetadatadispenser-openscope) method, except that the metadata of interest already exists in memory, rather than in a file on disk.

If the target area of memory does not contain common language runtime (CLR) metadata, the **OpenScopeOnMemory** method will fail.

## See also

[IMetaDataDispenser](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenser)