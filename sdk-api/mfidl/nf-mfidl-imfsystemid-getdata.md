# IMFSystemId::GetData

## Description

Retrieves system id data.

## Parameters

### `size`

The size in bytes of the returned data.

### `data`

Receives the returned data. The caller must free this buffer by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFSystemId](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsystemid)