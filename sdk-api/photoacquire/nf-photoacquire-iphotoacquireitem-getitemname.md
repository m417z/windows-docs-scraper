# IPhotoAcquireItem::GetItemName

## Description

The `GetItemName` method retrieves the file name for an item.

## Parameters

### `pbstrItemName` [out]

Pointer to a string containing the name of the item.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The file name consists of the display name and the extension, even if the **Hide extensions for known file types** setting is checked in the Windows **Folder Options** dialog box.

## See also

[IPhotoAcquireItem Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem)