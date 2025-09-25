# FmtIdToPropStgName function

## Description

The **FmtIdToPropStgName** function converts a property set format identifier (FMTID) to its storage or stream name.

## Parameters

### `pfmtid` [in]

A pointer to the FMTID of the property set.

### `oszName` [out]

A pointer to a null-terminated string that receives the storage or stream name of the property set identified by *pfmtid*. The array allocated for this string must be at least CCH_MAX_PROPSTG_NAME (32) characters in length.

## Return value

This function supports the standard return value E_INVALIDARG as well as the following:

## Remarks

**FmtIdToPropStgName** maps a property set FMTID to its stream name for a simple property set or to its storage name for a nonsimple property set.

This function is useful in creating or opening a property set using the PROPSETFLAG_UNBUFFERED value with the
[StgCreatePropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropstg) and
[StgOpenPropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenpropstg) functions. For more information about PROPSETFLAG_UNBUFFERED, see [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants).

## See also

[PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants)

[PropStgNameToFmtId](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-propstgnametofmtid)

[StgCreatePropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropstg)

[StgOpenPropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenpropstg)