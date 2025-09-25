# IUIAnimationTransition::GetDuration

## Description

Gets the duration of the transition.

## Parameters

### `duration` [out]

The duration of the transition, in seconds.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_VALUE_NOT_DETERMINED** | The requested value for the duration cannot be determined. |
| **UI_E_STORYBOARD_ACTIVE** | The storyboard for this transition is currently in the schedule. |

## Remarks

An application should typically call the [IUIAnimationTransition::IsDurationKnown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-isdurationknown) method before calling this method. This method should not be called when the storyboard to which the transition has been added is scheduled or playing.

#### Examples

The following shows how to get the duration of a transition.

```cpp
hr = pTransition->IsDurationKnown();
if (SUCCEEDED(hr))
{
    bool fDurationKnown = (hr == S_OK);
    if (fDurationKnown)
    {
        UI_ANIMATION_SECONDS duration;
        hr = pTransition->GetDuration(&duration);
        if (SUCCEEDED(hr))
        {
            ...
        }
    }
    else
    {
        ...
    }
}
```

## See also

[IUIAnimationTransition](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationtransition)

[IUIAnimationTransition::IsDurationKnown](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationtransition-isdurationknown)