# IPhotoAcquireSettings::GetFlags

## Description

The `GetFlags` method retrieves the photo acquire flags.

## Parameters

### `pdwPhotoAcquireFlags` [out]

Pointer to a double word value containing the photo acquire flags.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A non-NULL value was expected. |

## See also

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)

[SetFlags](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-setflags)