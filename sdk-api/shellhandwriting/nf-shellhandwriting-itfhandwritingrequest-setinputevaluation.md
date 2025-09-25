# SetInputEvaluation function

## Description

Sets how the pen input should be recognized.

## Parameters

### `inputEvaluation` [in]

How the pen input should be recognized.

## Return value

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

Once pointer input is deemed to be an ink gesture (such as a tap or press and hold to cancel handwriting), this method must be called after [RequestHandwritingForPointer](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-requesthandwritingforpointer) when the current handwriting state for the *pointerId* is set to [TF_HANDWRITING_POINTERDELIVERY](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate) or [TF_USE_POINTER_DELIVERY](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfproximatehandwritingtargetresponse) is the response to a handwriting proximity callback.

If a tap is detected, *inputEvaluation* should be set to [TF_IE_TAP](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfinputevaluation) as this indicates that handwriting corrections should be shown.

If [TF_IE_TAP](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfinputevaluation) or [TF_IE_CANCELHANDWRITING](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfinputevaluation) are specified, handwriting will be abandoned. As the handwriting state was set to [TF_HANDWRITING_POINTERDELIVERY](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate), all pointer input will have already been delivered to the client.

If [TF_IE_HANDWRITING](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate) is specified, handwriting recognition will be initiated.

This method must be called within two seconds of calling [RequestHandwritingForPointer](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-requesthandwritingforpointer). If this method is not called within this two second time frame, the handwriting operation will be abandoned (equivalent to calling this method and specifying [TF_IE_CANCELHANDWRITING](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate)).

## See also

[TfInputEvaluation enumeration](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfinputevaluation)