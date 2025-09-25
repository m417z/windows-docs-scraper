# IUIAnimationVariable2::SetTag

## Description

Sets the tag of the animation variable.

## Parameters

### `object` [in, optional]

The object portion of the tag. This parameter can be **NULL**.

### `id` [in]

The identifier portion of the tag.

## Return value

Returns **S_OK** if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*), and it can be used by an application to identify an animation variable.
Because **NULL** is a valid object component of a tag, the *object* parameter can be **NULL**.

## See also

[IUIAnimationManager2::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getvariablefromtag)

[IUIAnimationVariable2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable2)

[IUIAnimationVariable2::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable2-gettag)