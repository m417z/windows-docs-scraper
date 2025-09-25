# IFhScopeIterator::GetItem

## Description

Retrieves the current item in an inclusion or exclusion list.

> [!NOTE]
> **IFhScopeIterator** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `Item` [out]

This parameter must be **NULL** on input. On output, it receives a pointer to a string that contains the current element of the list. This element is a library name or a folder name, depending on the parameters that were passed to the [IFhConfigMgr::GetIncludeExcludeRules](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getincludeexcluderules) method. The string is allocated by calling [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring). You must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the string when it is no longer needed.

## Return value

**S_OK** on success, or an unsuccessful **HRESULT** on failure. Possible unsuccessful **HRESULT** values include values defined in the FhErrors.h header file.

## Remarks

To move to the next item in the inclusion or exclusion list, call the [IFhScopeIterator::MoveToNextItem](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhscopeiterator-movetonextitem) method.

## See also

[IFhScopeIterator](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhscopeiterator)

[IFhScopeIterator::MoveToNextItem](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhscopeiterator-movetonextitem)