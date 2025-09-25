# IUIAnimationVariable::GetTag

## Description

Gets the tag for an animation variable.

## Parameters

### `object` [out, optional]

The object portion of the tag.

### `id` [out, optional]

The identifier portion of the tag.

## Return value

If the method succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [Windows Animation Error Codes](https://learn.microsoft.com/windows/desktop/UIAnimation/uianimation-error-codes) for a list of error codes.

| Return code | Description |
| --- | --- |
| **UI_E_VALUE_NOT_SET** | The animation variable's tag was not set. |

## Remarks

A tag is a pairing of an integer identifier (*id*) with a COM object (*object*); it can be used by an application to identify an animation variable.

The parameters are optional so that the method can return both portions of the tag, or just the identifier or object portion.

## See also

[IUIAnimationManager::GetVariableFromTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationmanager-getvariablefromtag)

[IUIAnimationVariable](https://learn.microsoft.com/windows/desktop/api/uianimation/nn-uianimation-iuianimationvariable)

[IUIAnimationVariable::SetTag](https://learn.microsoft.com/windows/desktop/api/uianimation/nf-uianimation-iuianimationvariable-settag)