## Description

Contains a set of generic Cryptography API: Next Generation (CNG) buffers.

> [!NOTE]
> This struct is also aliased as NCryptBufferDesc.

## Members

### `ulVersion`

The version of the structure. This must be the following value.

| Value | Meaning |
| ----- | ------- |
| BCRYPTBUFFER_VERSION | The default version number. |

### `cBuffers`

The number of elements in the *pBuffers* array.

### `pBuffers`

The address of an array of [BCryptBuffer](https://learn.microsoft.com/windows/win32/api/bcrypt/ns-bcrypt-bcryptbuffer) structures that contain the buffers. *cBuffers* contains the number of elements in this array.

## Remarks

## See also

[BCryptDeriveKey function](https://learn.microsoft.com/windows/win32/api/bcrypt/nf-bcrypt-bcryptderivekey)