# IPhotoAcquire::Acquire

## Description

The `Acquire` method acquires photos from a device.

## Parameters

### `pPhotoAcquireSource` [in]

Pointer to an [IPhotoAcquireSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource) object representing the device from which to acquire photos. Initialize this object by calling [CreatePhotoSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-createphotosource).

### `fShowProgress` [in]

Flag that, when set to **TRUE**, indicates that a progress dialog will be shown.

### `hWndParent` [in]

Handle to a parent window.

### `pszApplicationName` [in]

Pointer to a null-terminated string containing the application name.

### `pPhotoAcquireProgressCB` [in]

Pointer to an optional [IPhotoAcquireProgressCB](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb) object.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Non-**NULL** pointer was expected. |

## Remarks

To initialize the *pPhotoAcquireSource* parameter passed to `Acquire`, [CreatePhotoSource](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-createphotosource) should be called prior to calling `Acquire`.

*pPhotoAcquireProgressCB* provides callback methods that allow you to apply further filtering or control as items are acquired.

To verify that there are items in the device before acquisition, or to selectively acquire items from the device, call [IPhotoAcquireSource::InitializeItemList](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresource-initializeitemlist) to enumerate the items before calling `Acquire`.

## See also

[IPhotoAcquire Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquire)

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)

[IPhotoAcquireSource Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresource)