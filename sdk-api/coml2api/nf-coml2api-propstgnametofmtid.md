# PropStgNameToFmtId function

## Description

The **PropStgNameToFmtId** function converts a property set storage or stream name to its format identifier.

## Parameters

### `oszName` [in]

A pointer to a null-terminated Unicode string that contains the stream name of a simple property set or the storage name of a nonsimple property set.

### `pfmtid` [out]

A pointer to a FMTID variable that receives the format identifier of the property set specified by *oszName*.

## Return value

This function supports the standard return value E_INVALIDARG as well as the following:

## Remarks

The **PropStgNameToFmtId** function maps the stream name of a simple property set or the storage name of a nonsimple property set to its format identifier.

This function is useful in creating or opening a property set using the PROPSETFLAG_UNBUFFERED value with the
[StgCreatePropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropstg) and
[StgOpenPropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenpropstg) functions. For more information about PROPSETFLAG_UNBUFFERED, see [PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants).

## See also

[FmtIdToPropStgName](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-fmtidtopropstgname)

[PROPSETFLAG Constants](https://learn.microsoft.com/windows/desktop/Stg/propsetflag-constants)

[StgCreatePropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatepropstg)

[StgOpenPropStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenpropstg)