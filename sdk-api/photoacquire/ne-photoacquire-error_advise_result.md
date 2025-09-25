# ERROR_ADVISE_RESULT enumeration

## Description

The `ERROR_ADVISE_RESULT` enumeration type indicates the type of error values that can be assigned to the *pnErrorAdviseResult* parameter of [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise).

## Constants

### `PHOTOACQUIRE_RESULT_YES:0`

Specifies a Yes response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_YESNO.

### `PHOTOACQUIRE_RESULT_NO:1`

Specifies a No response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_YESNO.

### `PHOTOACQUIRE_RESULT_OK:2`

Specifies an OK response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_OK.

### `PHOTOACQUIRE_RESULT_SKIP:3`

Specifies a Skip response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL.

### `PHOTOACQUIRE_RESULT_SKIP_ALL:4`

Specifies a Skip All response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL.

### `PHOTOACQUIRE_RESULT_RETRY:5`

Specifies a Retry response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL or PHOTOACQUIRE_ERROR_RETRYCANCEL.

### `PHOTOACQUIRE_RESULT_ABORT:6`

Specifies a Cancel response to an error dialog. Valid only if the *nMessageType* parameter to [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise) is PHOTOACQUIRE_ERROR_SKIPRETRYCANCEL or PHOTOACQUIRE_ERROR_RETRYCANCEL.

## Remarks

The type of response allowed is of type [ERROR_ADVISE_MESSAGE_TYPE](https://learn.microsoft.com/windows/win32/api/photoacquire/ne-photoacquire-error_advise_message_type), and indicated by the *nMessageType* parameter of [IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise).

## See also

[ERROR_ADVISE_MESSAGE_TYPE](https://learn.microsoft.com/windows/win32/api/photoacquire/ne-photoacquire-error_advise_message_type)

[Enumeration Types](https://learn.microsoft.com/previous-versions/windows/desktop/acquisition/enumeration-types)

[IPhotoAcquireProgressCB::ErrorAdvise](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquireprogresscb-erroradvise)