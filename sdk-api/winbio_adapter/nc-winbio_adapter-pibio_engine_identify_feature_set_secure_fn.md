# PIBIO_ENGINE_IDENTIFY_FEATURE_SET_SECURE_FN callback function

## Description

Called by the Windows Biometric Framework to build a template from the current feature set and locate a matching template in the database. If a match can be found, the engine adapter must fill the *Identity*, *SubFactor*, *Authorization*, and *AuthorizationSize* fields.

## Parameters

### `Pipeline`

Pointer to a WINBIO_PIPELINE structure associated with the biometric unit performing the operation.

### `Nonce`

Pointer to a buffer that contains a nonce.

### `NonceSize`

Size, in bytes, of the buffer specified by the *Nonce* parameter.

### `KeyIdentifier`

Pointer to a buffer that contains an identifier for the key from a previous call to [EngineAdapterCreateKey](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_create_key_fn)

### `KeyIdentifierSize`

Size, in bytes, of the buffer specified by the *KeyIdentifier* parameter.

### `Identity`

Pointer to a [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure that contains the SID of the template recovered from the database. This value is returned only if a match is found.

### `SubFactor`

### `RejectDetail`

Pointer to a variable that receives additional information if a capture failure prevents the engine from performing a matching operation. If the most recent capture succeeded, set this parameter to zero.

### `Authorization`

An HMAC. See remarks section.

### `AuthorizationSize`

Size, in bytes, of the buffer specified by the *Authorization* parameter.

### `Subfactor`

A [WINBIO_BIOMETRIC_SUBTYPE Constants](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-biometric-subtype-constants) value that receives the sub-factor associated with the template in the database. See the Remarks section for more details. This value is returned only if a match is found.

## Return value

**WINBIO_E_INVALID_KEY_IDENTIFIER** must be returned in the case where the key cannot be used for whatever reason. When **WINBIO_E_INVALID_KEY_IDENTIFIER**  is returned, the sensor and TPM will be re-provisioned.

## Remarks

The Authorization buffer contains the following SHA256_HMAC:

SHA256_HMAC(Key, SHA256(Nonce || 0xffffffe2 || SHA256(AccountSid)))

* Key

  Key is the HMAC key passed in by [EngineAdapterCreateKey](https://learn.microsoft.com/windows/desktop/api/winbio_adapter/nc-winbio_adapter-pibio_engine_create_key_fn), and identified by the *KeyIdentifier* parameter.
* Nonce

  Nonce is the Nonce parameter.
* 0xffffffe2

  A 32-bit unsigned integer in big-endian format.
* AccountSid

  The account SID of the user referenced by the Identity parameter. The SID bytes can be obtained from the [WINBIO_IDENTITY](https://learn.microsoft.com/windows/desktop/SecBioMet/winbio-identity) structure.

#### Examples

Here is a pseudocode implementation of the SHA256 HMAC calculation:

```
// Hash the AccountSid.
    assert(Identity->Type == WINBIO_ID_TYPE_SID);
    hashHandle = CreateHash(SHA256_ALGORITHM);
    HashData(
        hashHandle,
        Identity->Value.AccountSid.Data,
        Identity->Value.AccountSid.Size);
    identityHash = FinishHash(hashHandle);

    // Hash the parameters.
    BYTE bytes[] = {0xff, 0xff, 0xff, 0xe2};
    hashHandle = CreateHash(SHA256_ALGORITHM);
    HashData(hashHandle, Nonce, NonceSize);
    HashData(hashHandle, bytes, sizeof(bytes));
    HashData(hashHandle, identityHash, SHA256_DIGEST_LENGTH);
    parameterHash = FinishHash(hashHandle);

    // Calculate the authorization HMAC
    key, keySize = GetKeyFromIdentifier(KeyIdentifier, KeyIdentifierSize);
    hashHandle = CreateHash(HMAC_SHA256_ALGORITHM, key, keySize);
    HashData(hashHandle, parameterHash, SHA256_DIGEST_LENGTH);
    authorization = FinishHash(hashHandle);

```