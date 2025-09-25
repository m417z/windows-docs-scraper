# ImmAssociateContextEx function

## Description

Changes the association between the input method context and the specified window or its children.

## Parameters

### `unnamedParam1` [in]

Handle to the window to associate with the input context.

### `unnamedParam2` [in]

Handle to the input method context.

### `unnamedParam3` [in]

Flags specifying the type of association between the window and the input method context. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **IACE_CHILDREN** | Associate the input method context to the child windows of the specified window only. |
| **IACE_DEFAULT** | Restore the default input method context of the window. |
| **IACE_IGNORENOCONTEXT** | Do not associate the input method context with windows that are not associated with any input method context. |

## Return value

Returns **TRUE** if successful or **FALSE** otherwise.

## Remarks

If the application calls this function with IACE_CHILDREN, the operating system associates the specified input method context with child windows of the window indicated by *hWnd*. It associates the input method context only with child windows of the thread that creates *hWnd*. Any child window that is created after this function has been called will not be affected. Instead, the default input method context will be associated with it.

If the application calls this function with IACE_DEFAULT, the operating system restores the default input method context for the window. In this case, the *hIMC* parameter is ignored.

## See also

[Input Method Manager](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager)

[Input Method Manager Functions](https://learn.microsoft.com/windows/desktop/Intl/input-method-manager-functions)