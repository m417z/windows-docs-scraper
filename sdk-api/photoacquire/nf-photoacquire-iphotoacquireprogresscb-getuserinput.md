# IPhotoAcquireProgressCB::GetUserInput

## Description

The `GetUserInput` method overrides the default functionality that displays a message prompting the user for string input during acquisition. The application provides the implementation of the `GetUserInput` method.

## Parameters

### `riidType` [in]

Specifies the interface ID of the prompt type. This may only be IID_IUserInputString.

### `pUnknown` [in]

Pointer to an object of the prompt class. Currently, this must be an [IUserInputString](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iuserinputstring) object.

### `pPropVarResult` [out]

Pointer to a property variant object representing the descriptive input to be obtained. Must be freed by the caller using PropVariantClear.

If the application's implementation of `GetUserInput` returns a value other than E_NOTIMPL, the value of *pPropVarDefault* must be copied to the *pPropVarResult* parameter.

### `pPropVarDefault` [in]

Pointer to a property variant object representing the default value of the input being requested.

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Return E_NOTIMPL if the default functionality is desired |

## Remarks

If this method is implemented, the implementation should copy the value of the *pPropVarDefault* argument to the *pPropVarResult* parameter.

If this method returns an HRESULT other than E_NOTIMPL, the default dialog box that prompts the user will not be displayed.

If the progress dialog box is suppressed in [IPhotoAcquire::Acquire](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquire-acquire), this method must be implemented in order to assign a default value to the *pPropVarResult* parameter. Normally a value is supplied to *pPropVarResult* in the course of prompting the user with the default dialog, but when the dialog is suppressed, the application must copy the value of the *pPropVarDefault* argument to the *pPropVarResult* parameter.

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)