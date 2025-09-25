# IWICComponentInfo::GetVersion

## Description

Retrieves the component's version.

## Parameters

### `cchVersion` [in]

Type: **UINT**

The size of the *wzVersion* buffer.

### `wzVersion` [in, out]

Type: **WCHAR***

A pointer that receives a culture invariant string of the component's version.

### `pcchActual` [out]

Type: **UINT***

A pointer that receives the actual length of the component's version. The version is optional; if a value is not specified by the component, the length returned is 0.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

All built-in components return "1.0.0.0", except for pixel formats, which do not have a version.

If *cchAuthor* is 0 and *wzAuthor* is **NULL**, the required buffer size is returned in *pccchActual*.