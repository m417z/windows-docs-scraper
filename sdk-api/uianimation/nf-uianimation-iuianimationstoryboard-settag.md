# IUIAnimationStoryboard::SetTag

## Description

Sets the tag for the storyboard.

## Parameters

### `object` [in, optional]

The object portion of the tag.
This parameter can be **NULL**.

### `id` [in]

The identifier portion of the tag.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_STORYBOARD_ACTIVE** | The storyboard is currently in the schedule. |

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*); it can be used by an application to identify a storyboard.

## See also

[IUIAnimationManager::GetStoryboardFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getstoryboardfromtag)

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboard::GetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationstoryboard-gettag)