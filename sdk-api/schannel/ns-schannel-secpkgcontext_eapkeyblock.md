# SecPkgContext_EapKeyBlock structure

## Description

The **SecPkgContext_EapKeyBlock** structure contains key data used by the EAP TLS Authentication Protocol. For information about the EAP TLS Authentication Protocol, see [http://www.ietf.org/rfc/rfc2716.txt](https://www.ietf.org/rfc/rfc2716.txt).

## Members

### `rgbKeys`

An array of 128 bytes that contain key data used by the EAP TLS Authentication Protocol.

### `rgbIVs`

An array of 64 bytes that contain initialization vector data used by the EAP TLS Authentication Protocol.