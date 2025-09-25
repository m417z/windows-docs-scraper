# IMathInputControl::LoadInk

## Description

Processes ink and triggers recognition.

## Parameters

### `Ink` [in]

The ink object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method will only work when the control is visible.
When that ink exceeds the control's current size, and automatic growth is enabled, the control tries to accommodate the input. If the control cannot supply enough space, ink is proportionally shrunk to fit the maximum available size.

## See also

[EnableAutoGrow](https://learn.microsoft.com/windows/desktop/api/micaut/nf-micaut-imathinputcontrol-enableautogrow)

[IMathInputControl](https://learn.microsoft.com/windows/desktop/api/micaut/nn-micaut-imathinputcontrol)