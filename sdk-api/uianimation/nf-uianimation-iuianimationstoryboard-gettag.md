# IUIAnimationStoryboard::GetTag

## Description

Gets the tag for a storyboard.

## Parameters

### `object` [out, optional]

The object portion of the tag.

### `id` [out, optional]

The identifier portion of the tag.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_VALUE_NOT_SET** | The storyboard's tag was not set. |

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*); it can be used by an application to identify a storyboard.

The parameters are optional so that the method can return both portions of the tag, or just the identifier or object portion.

## See also

[IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-settag)