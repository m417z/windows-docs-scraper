# IPhotoAcquirePlugin::ProcessItem

## Description

The `ProcessItem` method provides additional functionality each time an item is processed. The application provides the implementation of the `ProcessItem` method.

## Parameters

### `dwAcquireStage` [in]

Specifies a double word value indicating whether this method is being called before or after processing an item. Must be one of: PAPS_PRESAVE, PAPS_POSTSAVE, or PAPS_CLEANUP.

| Value | Description |
| --- | --- |
| PAPS_PRESAVE | Indicates that the method is being called before saving the acquired file. During PAPS_PRESAVE, [pPhotoAcquireItem::GetProperty](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireitem-getproperty) should be used to retrieve metadata from the original file, while new metadata to be written to the file should be added to *pPropertyStore*. |
| PAPS_POSTSAVE | Indicates that the method is being called after saving the acquired file. |
| PAPS_CLEANUP | Indicates that the user has canceled the acquire operation and any work done by the plug-in should be cleaned up. |

### `pPhotoAcquireItem` [in]

Pointer to an [IPhotoAcquireItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireitem) object for the item being processed.

### `pOriginalItemStream` [in]

Pointer to an **IStream** object for the original item. **NULL** if *dwAcquireStage* is PAPS_POSTSAVE.

### `pszFinalFilename` [in]

The file name of the destination of the item. **NULL** if *dwAcquireStage* is PAPS_PRESAVE.

### `pPropertyStore` [in]

The item's property store. **NULL** if *dwAcquireStage* is PAPS_POSTSAVE.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not implemented. |

## See also

[IPhotoAcquirePlugin Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireplugin)