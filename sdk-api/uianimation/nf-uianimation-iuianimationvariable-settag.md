# IUIAnimationVariable::SetTag

## Description

Sets the tag for an animation variable.

## Parameters

### `object` [in, optional]

The object portion of the tag.
This parameter can be **NULL**.

### `id` [in]

The identifier portion of the tag.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*); it can be used by an application to identify an animation variable.
Because **NULL** is a valid object component of a tag, the *object* parameter can be **NULL**.

## See also

[IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-gettag)