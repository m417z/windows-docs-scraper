# IDMLObject::SetName

## Description

Associates a name with the DirectML device object.
This name is for use in debug diagnostics and tools. This method is thread-safe.

## Parameters

### `name`

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **NULL**-terminated **UNICODE** string that contains the name to associate with the DirectML device object.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLObject](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlobject)