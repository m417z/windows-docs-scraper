# IPhotoAcquire::EnumResults

## Description

The `EnumResults` method retrieves an enumeration containing the paths of all files successfully transferred during the most recent call to [Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire).

## Parameters

### `ppEnumFilePaths` [out]

Returns an enumeration containing the paths to all the transferred files.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A non-**NULL** pointer was expected. |

## Remarks

If the file transfer is aborted before any files are transferred, *ppEnumFilePaths* will be set to **NULL**.

## See also

[IPhotoAcquire Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquire)

[IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire)