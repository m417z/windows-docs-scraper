# IAppxFactory::CreateValidatedBlockMapReader

## Description

Creates a read-only block map object model from contents provided by an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) and a digital signature.

## Parameters

### `blockMapStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream that delivers block map XML for reading. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat).

### `signatureFileName` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The file that contains a digital signature used to validate the contents of the input stream.

### `blockMapReader` [out, retval]

Type: **[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)****

The block map reader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those below. This method might return errors that are passed from the underlying validation APIs that are used.
For example, this method might return "Crypto and WinTrust error codes (0x8009xxxx, 0x800bxxxx) if the signature can't be read, is invalid, or doesn't match the content of *blockMapStream*.

| Return code | Description |
| --- | --- |
| **APPX_E_INVALID_BLOCKMAP** | The *blockMapStream* does not contain syntactically valid XML for the block map. |

## Remarks

This method is used when the block map exists alone, outside of an app package. The block map object provides access to all data elements and attributes in the block map XML.

The *fileName* parameter should include the path of a package digital signature (.p7x) file on disk. If this parameter is not **NULL**, this method will validate the format of the signature file and validate the contents of *blockMapStream* against the signature.

## See also

[IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory)

[IAppxFactory::CreateBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxfactory-createblockmapreader)