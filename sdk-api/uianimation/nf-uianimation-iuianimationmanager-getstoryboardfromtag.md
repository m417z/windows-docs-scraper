# IUIAnimationManager::GetStoryboardFromTag

## Description

Gets the storyboard with the specified tag.

## Parameters

### `object` [in, optional]

The object portion of the tag.
This parameter can be **NULL**.

### `id` [in]

The identifier portion of the tag.

### `storyboard` [out]

The storyboard that matches the specified tag, or **NULL** if no match is found.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*). An application can use tags to identify animation variables and storyboards. **NULL** is a valid object component of a tag; therefore, the *object* parameter can be **NULL**.

Tags are not necessarily unique; this method returns UI_E_AMBIGUOUS_MATCH if more than one storyboard exists with the specified tag.

## See also

[IUIAnimationManager](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationmanager)

[IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)

[IUIAnimationStoryboard::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-settag)