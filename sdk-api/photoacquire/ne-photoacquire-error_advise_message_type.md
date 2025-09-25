# ERROR_ADVISE_MESSAGE_TYPE enumeration

## Description

The `ERROR_ADVISE_MESSAGE_TYPE` enumeration type indicates the type of error values that can be passed to the *nMessageType* parameter of [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise).

## Constants

### `PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL:0`

Specifies that the error that occurred requires a Skip, Retry, or Cancel response. The *pnErrorAdviseResult* parameter to [IPhotoAcquireProgressDialogCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) must be one of the following: **PHOTOACQUIRE_RESULT_SKIP**, **PHOTOACQUIRE_RESULT_SKIP_ALL**, **PHOTOACQUIRE_RESULT_RETRY**, or **PHOTOACQUIRE_RESULT_ABORT**.

### `PHOTOACQUIRE_ERROR_RETRYCANCEL:1`

Specifies that the error that occurred requires a Retry or Cancel response. The *pnErrorAdviseResult* parameter to [IPhotoAcquireProgressDialogCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) must be one of the following: **PHOTOACQUIRE_RESULT_RETRY** or **PHOTOACQUIRE_RESULT_ABORT**.

### `PHOTOACQUIRE_ERROR_YESNO:2`

Specifies that the error that occurred requires a Yes or No response. The *pnErrorAdviseResult* parameter to [IPhotoAcquireProgressDialogCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) must be one of the following: **PHOTOACQUIRE_RESULT_YES** or **PHOTOACQUIRE_RESULT_NO**.

### `PHOTOACQUIRE_ERROR_OK:3`

Specifies that the error that occurred requires an OK response. The *pnErrorAdviseResult* parameter to [IPhotoAcquireProgressDialogCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) must be **PHOTOACQUIRE_RESULT_OK**.

## See also

[ERROR_ADVISE_RESULT](https://learn.microsoft.com/windows/desktop/api/photoacquire/ne-photoacquire-error_advise_result)

[Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/acquisition/enumeration-types)

[IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise)