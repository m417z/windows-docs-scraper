# IUIAnimationStoryboard2::GetTag

## Description

Gets the tag for a storyboard.

## Parameters

### `object` [out, optional]

The object portion of the tag.

### `id` [out, optional]

The identifier portion of the tag.

## Return value

If this method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_VALUE_NOT_SET** | The storyboard tag was not set. |

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*); it can be used by an application to identify a storyboard.

This method can return the identifier, the object, or both portions of the tag.

## See also

[IUIAnimationManager2::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager2-getstoryboardfromtag)

[IUIAnimationStoryboard2](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard2)

[IUIAnimationStoryboard2::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard2-settag)