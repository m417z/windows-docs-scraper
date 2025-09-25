# MFCancelCreateFile function

## Description

Cancels an asynchronous request to create a byte stream from a file.

## Parameters

### `pCancelCookie` [in]

A pointer to the **IUnknown** interface of the cancellation object. This pointer is received in the *ppCancelCookie* parameter of the [MFBeginCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbegincreatefile) function.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

You can use this function to cancel a previous call to [MFBeginCreateFile](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfbegincreatefile). Because that function is asynchronous, however, it might complete before the operation can be canceled. Therefore, your callback might still be invoked after you call this function.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)