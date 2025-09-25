# IAppxPackageWriter::AddPayloadFile

## Description

Adds a new payload file to the app package.

## Parameters

### `fileName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the payload file. The file name path must be relative to the root of the package.

### `contentType` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The string specifying the [content type](https://www.w3.org/Protocols/rfc2616/rfc2616.html) of *fileName*.

### `compressionOption` [in]

Type: **[APPX_COMPRESSION_OPTION](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_compression_option)**

The type of compression to use to store *fileName* in the package.

### `inputStream` [in]

Type: **IStream***

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) providing the contents of *fileName*.
The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat).

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table. Error OPC codes, in addition to OPC_E_DUPLICATE_PART may result. If the method fails, the package writer will close in a failed state and can't be used any more.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The compression option specified by *compressionOption* is not one of the values of the [APPX_COMPRESSION_OPTION](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_compression_option) enumeration. |
| **E_NOT_VALID_STATE** | The writer is closed. |
| **HRESULT_FROM_WIN32(ERROR_INVALID_NAME)** | The file name specified is not a valid file name or is a reserved name for a footprint file. |
| **OPC_E_DUPLICATE_PART** | The file name specified is already in use in the package. |

## Remarks

When the **AddPayloadFile** method succeeds the contents of the specified *fileName* are written to the package and a corresponding entry is made in the package block map.

**Note** Files with the following reserved filenames cannot be added to the package using the **AddPayloadFile** method:

`AppxManifest.xml`, `AppxBlockMap.xml`, `AppxStreamMap.xml`, and `AppxSignature.p7x`.

Also, files with the following reserved folder prefixes cannot be added to the package using the **AddPayloadFile** method: `\AppxMetadata\` and `\Microsoft.System.Package.Metadata\`.

#### Examples

For an example, see [How to create an app package](https://learn.microsoft.com/windows/desktop/appxpkg/how-to-create-a-package).

## See also

[APPX_COMPRESSION_OPTION](https://learn.microsoft.com/windows/desktop/api/appxpackaging/ne-appxpackaging-appx_compression_option)

[IAppxPackageWriter](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxpackagewriter)