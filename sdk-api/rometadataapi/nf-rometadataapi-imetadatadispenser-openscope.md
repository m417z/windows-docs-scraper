## Description

Opens an existing file from disk, and maps its metadata into memory for importing (reading).

## Parameters

### `szScope` [in]

The name of the file to be opened. The file must contain common language runtime (CLR) metadata.

### `dwOpenFlags` [in]

Specifies the mode (read, and so on) for opening. This is a value of the [CorOpenFlags](https://learn.microsoft.com/dotnet/framework/unmanaged-api/metadata/coropenflags-enumeration) enumeration. You can only import (read) from the file, not emit (write) to it.

### `riid` [in]

The IID of the desired metadata interface to be returned; the caller will use the interface to import (read) metadata.

Valid values for *riid* include **IID_IUnknown**, **IID_IMetaDataImport**, **IID_IMetaDataImport2**, **IID_IMetaDataAssemblyImport**, **IID_IMetaDataTables**, and **IID_IMetaDataTables2**.

### `ppIUnk` [out]

The pointer to the returned interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The in-memory copy of the metadata can be queried using methods from one of the "import" interfaces. If the target file doesn't contain CLR metadata, then the **OpenScope** method will fail.

## See also

[IMetaDataDispenser](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatadispenser)