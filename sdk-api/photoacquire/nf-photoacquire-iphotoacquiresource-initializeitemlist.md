# IPhotoAcquireSource::InitializeItemList

## Description

The `InitializeItemList` method enumerates transferable items on the device and passes each item to the optional progress callback, if it is supplied.

## Parameters

### `fForceEnumeration` [in]

Flag that, if set to **TRUE**, indicates that enumeration will be repeated even if the item list has already been initialized. If set to **FALSE**, this flag indicates that repeated calls to `InitializeItemList` after the item list has already been initialized will not enumerate items again.

### `pPhotoAcquireProgressCB` [in]

Optional. Pointer to an [IPhotoAcquireProgressCB](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb) object.

### `pnItemCount` [out]

Returns the number of items found.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Non-**NULL** pointer was expected. |

## Remarks

If [IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire) is called without first calling `InitializeItemList`, initialization of the item list is done implicitly.

The first time the item list is initialized—either implicitly through [IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire) or explicitly by calling `InitializeItemList`—each item is enumerated. During enumeration, if an [IPhotoAcquireProgressCB](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb) object is passed to `InitializeItemList`, its implementation of [StartEnumeration](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-startenumeration), [FoundItem](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-founditem), and [EndEnumeration](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-endenumeration) may be used to apply further filtering or control to the list of items to be transferred.

## See also

[IPhotoAcquire Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquire)

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)