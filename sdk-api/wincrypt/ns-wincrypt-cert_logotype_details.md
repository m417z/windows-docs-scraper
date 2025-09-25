# CERT_LOGOTYPE_DETAILS structure

## Description

The **CERT_LOGOTYPE_DETAILS** structure contains additional information about a logotype.

## Members

### `pwszMimeType`

The address of a null-terminated Unicode string that contains the Multipurpose Internet Mail Extensions (MIME) type of the logotype.

### `cHashedUrl`

The number of elements in the **rgHashedUrl** array.

### `rgHashedUrl`

An array of [CERT_HASHED_URL](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_hashed_url) structures that contain the hashed URLs of the logotype. The **cHashedUrl** member contains the number of elements in this array.

## See also

[CERT_LOGOTYPE_AUDIO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_audio)

[CERT_LOGOTYPE_IMAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_image)