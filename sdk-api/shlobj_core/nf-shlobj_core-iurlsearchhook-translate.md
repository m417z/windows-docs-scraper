# IURLSearchHook::Translate

## Description

Called by the browser when the browser cannot determine the protocol of a URL address.

## Parameters

### `pwszSearchURL` [out]

Type: **PWSTR**

The address of a wide character buffer that, on entry, contains the URL address for which the browser is trying to determine the protocol. On exit, this buffer contains the modified URL address if the method was successful. See the return value for more information.

### `cchBufferSize`

Type: **DWORD**

The size, in characters, of the buffer at *pwszSearchURL*.

## Return value

Type: **HRESULT**

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The URL address was completely translated. The *lpwszSearchURL* parameter contains the full URL address. The browser will not call any other URL Search Hooks and will attempt to browse to the modified address. |
| **S_FALSE** | The URL address has been partially processed, but further translation is still required. The *lpwszSearchURL* parameter contains the result of the processing. The browser will continue executing the rest of the URL Search Hooks. |
| **E_FAIL** | The URL address was not translated. The *lpwszSearchURL* parameter has not been modified. The browser will continue executing the rest of the URL Search Hooks. |