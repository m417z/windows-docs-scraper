# IUIAnimationStoryboard2::SetTag

## Description

Sets the tag for the storyboard.

## Parameters

### `object` [in, optional]

The object portion of the tag.
This parameter can be NULL.

### `id` [in]

The identifier portion of the tag.

## Return value

Returns S_OK if successful; otherwise an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*). It can be used by an application to identify a storyboard.

## See also

[IUIAnimationManager2::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getstoryboardfromtag)

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-gettag)