# IAppxFactory::CreateBlockMapReader

## Description

Creates a read-only block map object model from contents provided by an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `inputStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream that delivers the block map XML for reading. The stream must support [Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read), [Seek](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-seek), and [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat). If these methods fail, their error codes might be passed to and returned by this method.

### `blockMapReader` [out, retval]

Type: **[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)****

The block map reader.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. Otherwise, it returns an error code that includes, but is not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **APPX_E_INVALID_BLOCKMAP** | The *inputStream* does not contain syntactically valid XML for the block map. |

## Remarks

Use the **CreateBlockMapReader** method to read a block map outside of an app package. The *blockMapReader* provides access to all data elements and attributes in the block map XML.

## See also

[IAppxFactory](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxfactory)

[IAppxFactory::CreateValidatedBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nf-appxpackaging-iappxfactory-createvalidatedblockmapreader)