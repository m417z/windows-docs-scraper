# MFGetLocalId function

## Description

Gets the local system ID.

## Parameters

### `verifier` [in]

Application-specific verifier value.

### `size`

Length in bytes of verifier.

### `id` [in]

Returned ID string. This value must be freed by the caller by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)