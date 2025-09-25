# IBrowserService::DisplayParseError

## Description

Deprecated. Displays a URL that failed to be successfully parsed by [IBrowserService::IEParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-ieparsedisplayname).

## Parameters

### `hres` [in]

Type: **HRESULT**

An **HRESULT** returned by [IBrowserService::IEParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-ieparsedisplayname). If this parameter is a success code, E_OUTOFMEMORY, or HRESULT_FROM_WIN32(ERROR_CANCELLED), this method does nothing.

### `pwszPath` [in]

Type: **LPCWSTR**

A pointer to a buffer containing the URL that failed to parse. This method displays the failed URL in an error dialog box.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **HRESULT** returned by [IBrowserService::IEParseDisplayName](https://learn.microsoft.com/windows/desktop/api/shdeprecated/nf-shdeprecated-ibrowserservice-ieparsedisplayname) can be passed to **IBrowserService::DisplayParseError** without first checking for success or failure.