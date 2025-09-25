# IMFNetResourceFilter::OnRedirect

## Description

Called when the byte stream redirects to a URL.

## Parameters

### `pszUrl` [in]

The URL to which the connection has been redirected.

### `pvbCancel` [out]

To cancel the redirection, set this parameter to **VARIANT_TRUE**. To allow the redirection, set this parameter to **VARIANT_FALSE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFNetResourceFilter](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetresourcefilter)