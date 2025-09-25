# IEnumOleDocumentViews::Next

## Description

Retrieves the specified number of items in the enumeration sequence.

## Parameters

### `cViews` [in]

The number of items to be retrieved. If there are fewer than the requested number of items left in the sequence, this method retrieves the remaining elements.

If *pcFetched* is **NULL**, this parameter must be 1.

### `rgpView` [out]

An array of enumerated items.

The enumerator is responsible for calling [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref), and the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through each pointer enumerated. If *cViews* is greater than 1, the caller must also pass a non-**NULL** pointer passed to *pcFetched* to know how many pointers to release.

### `pcFetched` [in, out]

The number of items that were retrieved. This parameter is always less than or equal to the number of items requested. This parameter can be **NULL**, in which case the *cViews* parameter must be 1.

## Return value

If the method retrieves the number of items requested, the return value is S_OK. Otherwise, it is S_FALSE.

## Remarks

E_NOTIMPL is not allowed as a return value. If an error value is returned, no entries in the *rgpView* array are valid and no calls to Release are required.

## See also

[IEnumOleDocumentViews](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ienumoledocumentviews)

[IOleDocumentView](https://learn.microsoft.com/windows/desktop/api/docobj/nn-docobj-ioledocumentview)