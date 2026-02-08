## Description

Creates an instance of [IAppxPackageReader](https://learn.microsoft.com/windows/win32/api/appxpackaging/nn-appxpackaging-iappxpackagereader) for reading the contents of a bundle's payload file.

## Parameters

### `fileName` [in]

An LPCWSTR containing the file name of the package to read.

### `payloadPackageReader` [out]

Receives the created **IAppxPackageReader** instance.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
|------------------------------------------|--------------------------------------------------------|
| HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND) | There is no package file with the specified file name. |
| E_POINTER | The *fileName* or *payloadPackageReader* param is NULL.|

## Remarks

## See also