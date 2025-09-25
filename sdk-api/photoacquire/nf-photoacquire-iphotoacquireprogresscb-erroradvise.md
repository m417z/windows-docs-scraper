# IPhotoAcquireProgressCB::ErrorAdvise

## Description

The `ErrorAdvise` method provides custom error handling for errors that occur during acquisition. The application provides the implementation of the `ErrorAdvise` method.

## Parameters

### `hr` [in]

Specifies the error that occurred.

### `pszErrorMessage` [in]

Pointer to a null-terminated string containing the error message.

### `nMessageType` [in]

Integer value containing the message type. May be one of the following.

| Value | Description |
| --- | --- |
| **PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL** | Specifies that the error that occurred requires a Skip, Retry, or Cancel response. The *pnErrorAdviseResult* parameter must be set to one of the following: **PHOTOACQUIRE_RESULT_SKIP**, **PHOTOACQUIRE_RESULT_SKIP_ALL**, **PHOTOACQUIRE_RESULT_RETRY**, or **PHOTOACQUIRE_RESULT_ABORT**. |
| **PHOTOACQUIRE_ERROR_RETRYCANCEL** | Specifies that the error that occurred requires a Retry or Cancel response. The *pnErrorAdviseResult* parameter must be set to one of the following: **PHOTOACQUIRE_RESULT_RETRY** or **PHOTOACQUIRE_RESULT_ABORT**. |
| **PHOTOACQUIRE_ERROR_YESNO** | Specifies that the error that occurred requires a Yes or No response. The *pnErrorAdviseResult* parameter must be set to one of the following: **PHOTOACQUIRE_RESULT_YES** or **PHOTOACQUIRE_RESULT_NO**. |
| **PHOTOACQUIRE_ERROR_OK** | Specifies that the error that occurred requires an OK response. The *pnErrorAdviseResult* parameter must be set to **PHOTOACQUIRE_RESULT_OK**. |

### `pnErrorAdviseResult` [out]

Pointer to an integer value containing the error advise result. The result should be one of the acceptable types indicated by the *nMessageType* parameter, and must be one of the following:

| Value | Description |
| --- | --- |
| **PHOTOACQUIRE_RESULT_YES** | Specifies a Yes response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_YESNO**. |
| **PHOTOACQUIRE_RESULT_NO** | Specifies a No response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_YESNO**. |
| **PHOTOACQUIRE_RESULT_OK** | Specifies an OK response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_OK**. |
| **PHOTOACQUIRE_RESULT_SKIP** | Specifies a Skip response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL**. |
| **PHOTOACQUIRE_RESULT_SKIP_ALL** | Specifies a Skip All response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL**. |
| **PHOTOACQUIRE_RESULT_RETRY** | Specifies a Retry response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL** or **PHOTOACQUIRE_ERROR_RETRYCANCEL**. |
| **PHOTOACQUIRE_RESULT_ABORT** | Specifies a Cancel response. Valid if *nMessageType* is **PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL** or **PHOTOACQUIRE_ERROR_RETRYCANCEL**. |

## Return value

The method returns an **HRESULT**. Your implementation is not limited to the following return values. Any failing HRESULT other than E_NOTIMPL is fatal and will cause the transfer to abort.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | The method is not yet implemented |

## Remarks

Normally, a message is displayed when an error occurs during image acquisition. If suppression of this message is desired, implement `ErrorAdvise`.

## See also

[IPhotoAcquireProgressCB Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquireprogresscb)