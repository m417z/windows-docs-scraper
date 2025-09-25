# IActionProgress::QueryCancel

## Description

Provides information about whether the action is being canceled.

## Parameters

### `pfCancelled` [out]

Type: **BOOL***

A reference to a **BOOL** value that specifies whether the action is being canceled.

## Return value

Type: **HRESULT**

Return S_OK if successful, or an error value otherwise.

## Remarks

Call this method when a process must know whether an action has been canceled. Implementing this method requires the implementing class to query either an internal or external flag to provide this information, and store the result in the value of *pfCancelled*.

## See also

[IActionProgress](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iactionprogress)

[IActionProgress::ResetCancel](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iactionprogress-resetcancel)