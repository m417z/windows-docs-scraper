# IExtendTaskPad::GetTitle

## Description

The **IExtendTaskPad::GetTitle** method enables MMC to get the taskpad title text to display in taskpads that use MMC taskpad templates.

## Parameters

### `pszGroup` [in]

A pointer to a null-terminated string that contains the group name that identifies the taskpad. The group name is the string that follows the hash (#) in the string passed in the *ppViewType* parameter when MMC calls [IComponent::GetResultViewType](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getresultviewtype) to display the taskpad. If no group name is specified, *pszGroup* is a **NULL** string.

### `pszTitle` [out]

A pointer to the address of a null-terminated string that contains the title for the taskpad specified by *pszGroup*. This text is displayed at the top of the taskpad as the title for the entire taskpad. If *pszTitle* points to a **NULL** string, no title is displayed.

## Return value

This method can return one of these values.

## Remarks

Allocate the *pszTitle* string with the COM API function [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) (or the equivalent) and MMC will release it.

## See also

[IExtendTaskPad](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendtaskpad)