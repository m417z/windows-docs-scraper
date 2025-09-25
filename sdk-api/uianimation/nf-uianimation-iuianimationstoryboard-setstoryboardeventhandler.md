# IUIAnimationStoryboard::SetStoryboardEventHandler

## Description

Specifies a handler for storyboard events.

## Parameters

### `handler` [in, optional]

The handler to be called whenever storyboard status and update events occur.
The specified object must implement the [IUIAnimationStoryboardEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler) interface or be **NULL**. See Remarks.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

## Remarks

Passing **NULL** for the *handler* parameter causes Windows Animation to release its reference to any handler object you passed in earlier. This technique can be essential for breaking reference cycles without having to call the [IUIAnimationManager::Shutdown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-shutdown) method.

## See also

[IUIAnimationStoryboard](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboard)

[IUIAnimationStoryboardEventHandler](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationstoryboardeventhandler)