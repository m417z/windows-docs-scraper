# IInkRenderer::SetObjectTransform

## Description

Sets the [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object that represents the object transform that is used to render ink.

## Parameters

### `ObjectTransform` [in]

The [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object that represents the geometric transformation - rotation, scaling, shear, and reflection - values to use to transform the stroke coordinates within the ink space.

A **NULL** value for the *objectTransform* parameter correlates to the identity transform.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | *objectTransform* does not point to a compatible [InkTransform](https://learn.microsoft.com/windows/desktop/tablet/inktransform-class) object. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

The transformation applies to the points, but not the pen width.

Object transformation occurs before view transformation.

It is problematic to call this method in response to SENT message. Test whether you are processing a SENT message
by calling [InSendMesssageEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-insendmessageex) and then POST the message to yourself if the message was SENT.

## See also

[GetObjectTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-getobjecttransform)

[GetViewTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-getviewtransform)

[IInkRenderer](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkrenderer)

[InkRenderer Class](https://learn.microsoft.com/windows/desktop/tablet/inkrenderer-class)

[SetViewTransform Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrenderer-setviewtransform)