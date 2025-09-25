# IUserInputString::GetImage

## Description

The `GetImage` method retrieves the default image used to initialize an edit control.

## Parameters

### `nSize` [in]

Integer containing the size of the image.

### `phBitmap` [out]

Pointer to the handle that specifies the image bitmap.

### `phIcon` [out]

Pointer to the handle that specifies the image icon.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | A **NULL** pointer was passed where a non-**NULL** pointer is expected. |

## See also

[IUserInputString Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring)