# CERT_LOGOTYPE_DATA structure

## Description

The **CERT_LOGOTYPE_DATA** structure contains logotype data.

## Members

### `cLogotypeImage`

The number of elements in the **rgLogotypeImage** array.

### `rgLogotypeImage`

An array of [CERT_LOGOTYPE_IMAGE](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_image) structures that contain the logotype images. The **cLogotypeImage** member contains the number of elements in this array.

### `cLogotypeAudio`

The number of elements in the **rgLogotypeAudio** array.

### `rgLogotypeAudio`

An array of [CERT_LOGOTYPE_AUDIO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_audio) structures that contain the logotype audio clips. The **cLogotypeAudio** member contains the number of elements in this array.

## See also

[CERT_LOGOTYPE_INFO](https://learn.microsoft.com/windows/desktop/api/wincrypt/ns-wincrypt-cert_logotype_info)