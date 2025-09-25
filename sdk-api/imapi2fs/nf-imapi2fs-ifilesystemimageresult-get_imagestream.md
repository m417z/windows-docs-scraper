# IFileSystemImageResult::get_ImageStream

## Description

Retrieves the burn image stream.

## Parameters

### `pVal` [out]

An [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interface of the burn image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid or the *pstatstgis* parameter of the [IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) method is **NULL**.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |
| **STG_E_INVALIDFUNCTION** | The *grfStateFlag* parameter of the [IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) method is invalid. |

## See also

[IDiscFormat2Data::Write](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-write)

[IFileSystemImageResult](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimageresult)