# IFhScopeIterator::MoveToNextItem

## Description

Moves to the next item in the inclusion or exclusion list.

> [!NOTE]
> **IFhScopeIterator** is deprecated and may be altered or unavailable in future releases.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

If the current item is the last item in the list, or if the list is empty, this method returns `HRESULT_FROM_WIN32(ERROR_NOT_FOUND)`.

## See also

[IFhScopeIterator](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhscopeiterator)

[IFhScopeIterator::GetItem](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhscopeiterator-getitem)