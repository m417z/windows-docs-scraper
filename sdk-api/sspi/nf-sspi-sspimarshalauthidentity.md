# SspiMarshalAuthIdentity function

## Description

Serializes the specified identity structure into a byte array.

## Parameters

### `AuthIdentity` [in]

The identity structure to serialize.

### `AuthIdentityLength` [out]

The length, in bytes, of the *AuthIdentityByteArray* array.

### `AuthIdentityByteArray` [out]

A pointer to an array of byte values that represents the identity specified by the *AuthIdentity* parameter.

## Return value

If the function succeeds, it returns **SEC_E_OK**.

If the function fails, it returns a nonzero error code.