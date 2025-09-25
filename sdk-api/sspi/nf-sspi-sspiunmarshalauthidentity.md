# SspiUnmarshalAuthIdentity function

## Description

Deserializes the specified array of byte values into an identity structure.

## Parameters

### `AuthIdentityLength` [in]

The size, in bytes, of the *AuthIdentityByteArray* array.

### `AuthIdentityByteArray` [in]

The array of byte values to deserialize.

### `ppAuthIdentity` [out]

The deserialized identity structure.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.