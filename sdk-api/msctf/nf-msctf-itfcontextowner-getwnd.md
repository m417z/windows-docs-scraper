# ITfContextOwner::GetWnd

## Description

The **ITfContextOwner::GetWnd** method returns the handle to a window that corresponds to the current document.

## Parameters

### `phwnd` [out]

Receives a pointer to the handle of the window that corresponds to the current document. This parameter can be **NULL** if the document does not have the corresponding handle to the window.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

A document might not have a corresponding window handle if the document is in memory but not displayed on the screen or if the document is a windowless control and the control does not know the window handle of the owner of the windowless controls. Callers cannot assume that the *phwnd* parameter will receive a non-**NULL** value even if the method is successful. Callers can also receive a **NULL** value for the *phwnd* parameter.