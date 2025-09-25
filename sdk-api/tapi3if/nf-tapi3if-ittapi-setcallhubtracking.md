# ITTAPI::SetCallHubTracking

## Description

The
**SetCallHubTracking** method enables or disables CallHub tracking.

## Parameters

### `pAddresses` [in]

Pointer to a **VARIANT** containing a **SAFEARRAY** of
[ITAddress](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itaddress) interface pointers.

### `bTracking` [in]

VARIANT_TRUE to enable tracking, VARIANT_FALSE to disable.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The TAPI object has not been initialized. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[ITTAPI](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-ittapi)

[TAPI Object](https://learn.microsoft.com/windows/desktop/Tapi/tapi-object)