## Description

Verifies that a specific auxiliary input format is supported by the APO.

## Parameters

### `pRequestedInputFormat`

The input format that is to be verified.

### `ppSupportedInputFormat`

The APO populates this parameter with the supported input format closest to the format passed in to the method.

## Return value

HRESULT

| HRESULT | Description |
|---------------|--------------|
| S_OK | Successful completion. The APO should add a reference to *pRequestedInputFormat* and return it in *ppSupportedInputFormat* |
| S_FALSE | Format is not supported. The APO should return a suggested supported format in *ppSupportedInputFormat* |
| APOERR_FORMAT_NOT_SUPPORTED | Format is not supported. The APO should not modify *ppSupportedInputFormat*|
| E_POINTER | Invalid pointer passed to this function. |
| Other values | Another component is causing a failure. These failures are tracked by the system. |

## Remarks

If the APO can accept the requested format, it should add a reference to the requested format, return this as the supported output format, and return S_OK.

If the APO cannot accept the requested format it may suggest an alternate requested format. In this case it should create and return the suggested format, and return S_FALSE.

The returned supported format should be 'closest' to the requested format, meaning that the format should have the same values for the following properties, specified in priority order.

- sample format
- bit depth
- number of channels
- sample rate

The suggested format may only be different from the requested format if S_FALSE is returned. When returning any failure, the suggested format should be left untouched.

This API may be called at any time. The returned results will depend on the internal state of the APO which may
be manipulated by external user-interfaces. Once the APO is locked for processing, however, this format cannot and will not changed.

This method may not be called from a real-time processing thread.

## See also