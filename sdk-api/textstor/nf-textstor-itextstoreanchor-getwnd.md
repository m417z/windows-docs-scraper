# ITextStoreAnchor::GetWnd

## Description

The **ITextStoreAnchor::GetWnd** method returns the handle to a window that corresponds to the current text stream.

## Parameters

### `vcView` [in]

Specifies the [TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie) data type that corresponds to the current document.

### `phwnd` [out]

Receives a pointer to the handle of the window that corresponds to the current document. This parameter can be **NULL** if the document does not have the corresponding handle to the window.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The **TsViewCookie** data type is invalid. |

## Remarks

A document might not have a corresponding window handle if the document is in memory but not displayed on the screen, or if the document is a windowless control and the control does not recognize the window handle of the owner of the windowless controls. Callers cannot assume that the *phwnd* parameter will receive a non-**NULL** value even if the method is successful. Callers can also receive a **NULL** value for the *phwnd* parameter.

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)