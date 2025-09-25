# FreeInheritedFromArray function

## Description

The **FreeInheritedFromArray** function frees memory allocated by the
[GetInheritanceSource](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getinheritancesourcea) function.

## Parameters

### `pInheritArray` [in]

A pointer to the array of [INHERITED_FROM](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-inherited_froma) structures returned by [GetInheritanceSource](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getinheritancesourcea).

### `AceCnt` [in]

Number of entries in *pInheritArray*.

### `pfnArray` [in, optional]

Unused. Set to **NULL**.

## Return value

If the function succeeds, the function returns ERROR_SUCCESS.

If the function fails, it returns a nonzero error code defined in WinError.h.

## See also

[GetInheritanceSource](https://learn.microsoft.com/windows/desktop/api/aclapi/nf-aclapi-getinheritancesourcea)