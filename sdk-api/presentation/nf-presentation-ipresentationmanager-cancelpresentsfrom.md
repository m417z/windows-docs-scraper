## Description

Cancels any previously issued and still in-flight presents that have not yet displayed, and whose Present IDs are at least the passed in _`presentIdToCancelFrom`_.

## Parameters

### `presentIdToCancelFrom`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The identifier of the present from which to cancel presents that have been issued but not yet displayed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the function succeeds, it returns `S_OK`; otherwise, it returns an `HRESULT` value that indicates the error.

## Remarks

If any presents in the past have already been displayed, this call will not fail - those presents will simply not be canceled. The present retiring fence will not be signaled for any canceled presents, because when presents are canceled, they don't affect the currently displayed present or cause it to begin the retiring process. For this reason, it is suggested that after performing a present, an application queries buffer available events to find an available buffer to issue on the first present after a cancel. Once that present is queued, it allows the previously displayed present to begin the retiring process, and signal the present retiring fence.

## See also

[IPresentationBuffer::GetAvailableEvent](https://learn.microsoft.com/windows/win32/api/presentation/nf-presentation-ipresentationbuffer-getavailableevent)