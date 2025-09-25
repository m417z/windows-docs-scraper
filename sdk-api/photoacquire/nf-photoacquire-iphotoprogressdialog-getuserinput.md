# IPhotoProgressDialog::GetUserInput

## Description

Retrieves descriptive information entered by the user, such as the tag name of the images to store.

## Parameters

### `riidType` [in]

Specifies the interface identifier (ID) of the prompt type. Currently, the only supported value is IID_IUserInputString.

### `pUnknown` [in]

Pointer to an object of the prompt class. Currently, the only supported type is [IUserInputString](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring).

### `pPropVarResult` [out]

Pointer to a property variant that stores the user input. Must be freed by the caller using **ClearPropVariant**.

### `pPropVarDefault` [in]

Pointer to a property variant containing the default value to be used if no input is supplied.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The progress dialog has been suppressed |

## Remarks

If the progress dialog box has been suppressed in [IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire), and [IPhotoAcquireProgressCB::GetUserInput](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-getuserinput) is either not implemented, or returns E_NOTIMPL, this method will return S_FALSE, and *pPropVarResult* will contain the value stored in the optional *pPropVarDefault* argument.

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)

[IPhotoProgressDialog Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoprogressdialog)