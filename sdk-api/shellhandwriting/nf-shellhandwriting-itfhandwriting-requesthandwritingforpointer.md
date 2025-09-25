# RequestHandwritingForPointer function

## Description

Requests that the specified pointer and ink stroke be used for the handwriting experience.

## Parameters

### `pointerId` [in]

The pointer identifier.

### `handwritingStrokeId` [in]

The ink stroke identifier.

You must call [GetHandwritingStrokeIdForPointer](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-gethandwritingstrokeidforpointer) to retrieve the unique ID of the stroke started by a [WM_POINTERDOWN](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdown) message.

### `requestAccepted` [out]

True, if the request was accepted; otherwise, false.

### `request` [out]

A pointer to an [ITfHandwritingRequest](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nn-shellhandwriting-itfhandwritingrequest) object.

## Return value

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

This method can only be called when the current handwriting state for the *pointerId* is set to [TF_HANDWRITING_POINTERDELIVERY](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate) or [TF_USE_POINTER_DELIVERY](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfproximatehandwritingtargetresponse) is the response to a handwriting proximity callback, otherwise it will return E_INVALIDARG.

This method must be called within two seconds of receiving a [WM_POINTERDOWN](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdown) message for *pointerId*. If this method is not called within this two second time frame, S_OK is returned, but *requestAccepted* will be set to false.

## See also

[SetHandwritingState](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-sethandwritingstate)