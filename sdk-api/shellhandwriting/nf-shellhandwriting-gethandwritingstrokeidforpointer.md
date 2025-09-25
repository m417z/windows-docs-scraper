# GetHandwritingStrokeIdForPointer function

## Description

Retrieves the unique ID of the ink stroke associated with the specified pointer ID.

## Parameters

### `pointerId` [in]

The pointer ID associated with the ink stroke.

### `handwritingStrokeId` [out]

The ID of the ink stroke associated with the *pointerId*.

## Return value

If the method succeeds, it returns **S_OK**; otherwise, it returns an **HRESULT** error code.

## Remarks

Clients using the [SetHandwritingState function](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-sethandwritingstate) to configure the current handwriting state to [TF_HANDWRITING_POINTERDELIVERY](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate) must call this function to retrieve the unique ID of the stroke started by a [WM_POINTERDOWN](https://learn.microsoft.com/windows/win32/inputmsg/wm-pointerdown) message (to pass to the [RequestHandwritingForPointer function](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-requesthandwritingforpointer)).

This function must be called on the same thread as the one handling the WM_POINTERDOWN message.

## See also