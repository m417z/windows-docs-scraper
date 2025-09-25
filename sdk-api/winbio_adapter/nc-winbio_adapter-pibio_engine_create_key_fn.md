# PIBIO_ENGINE_CREATE_KEY_FN callback function

## Description

Called by the Windows Biometric Framework to push an HMAC key to the sensor. The returned key identifier will be passed back to the biometric unit when the framework calls [EngineAdapterIdentifyFeatureSetSecure](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_identify_feature_set_secure_fn).

## Parameters

### `Pipeline`

Pointer to a [WINBIO_PIPELINE](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/ns-winbio_adapter-winbio_pipeline) structure associated with the biometric unit performing the operation.

### `Key`

Pointer to a buffer that contains the HMAC key.

### `KeySize`

Size, in bytes, of the buffer specified by the **Key** parameter.

### `KeyIdentifier`

Pointer to a buffer that receives a key identifier. The format of the buffer is vendor-defined.

### `KeyIdentifierSize`

Size, in bytes, of the buffer specified by the **KeyIdentifier** parameter.

### `ResultSize`

Pointer to a variable that receives the size, in bytes, of the data written to the buffer specified by the **KeyIdentifier** parameter.

## Return value

If the **KeyIdentifier** buffer is too small, **WINBIO_E_KEY_IDENTIFIER_BUFFER_TOO_SMALL** must be returned, and the required size must be written to *ResultSize*. The framework will call the API again with a larger buffer.
If the sensor cannot create the key, **WINBIO_E_KEY_CREATION_FAILED** must be returned.

## Remarks

Only a single key will be in use at any time. If **EngineAdapterCreateKey** is called when the engine has knowledge of a preexisting key, the preexisting key must be overwritten with the new one.