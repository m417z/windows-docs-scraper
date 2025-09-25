# IMetaDataDispenser::DefineScope

## Description

Creates a new area in memory in which you can create new metadata.

## Parameters

### `rclsid` [in]

The CLSID of the version of metadata structures to be created.

### `dwCreateFlags` [in]

Flags that specify options.

### `riid` [in]

The IID of the desired metadata interface to be returned. The caller will use the interface to create the new metadata.

The value of riid must specify one of the "emit" interfaces. Valid values are **IID_IMetaDataEmit**, **IID_IMetaDataAssemblyEmit**, or **IID_IMetaDataEmit2**.

### `ppIUnk` [out]

The pointer to the returned interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**DefineScope** creates a set of in-memory metadata tables, generates a unique GUID (module version identifier, or MVID) for the metadata, and creates an entry in the module table for the compilation unit being emitted.

## See also

[IMetaDataDispenser](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenser)