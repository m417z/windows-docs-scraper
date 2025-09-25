# ITextStoreAnchor::GetActiveView

## Description

The **ITextStoreAnchor::GetActiveView** method returns a [TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie) data type that specifies the current active view. TSF supports only a single active view, so a given text store should always return the same **TsViewCookie** data type.

## Parameters

### `pvcView` [out]

Receives the **TsViewCookie** data type that specifies the current active view.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *pvcView* is invalid. |

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[TsViewCookie](https://learn.microsoft.com/windows/desktop/TSF/tsviewcookie)