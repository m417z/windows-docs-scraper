# _SECURE_ELEMENT_ENDPOINT_LIST structure

## Description

The output parameter for [IOCTL_NFCSE_ENUM_ENDPOINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ni-nfcsedev-ioctl_nfcse_enum_endpoints).

## Members

### `NumberOfEndpoints`

The number of enumerated endpoints on the NFC controller.

### `EndpointList[ANYSIZE_ARRAY]`

An array of [SECURE_ELEMENT_ENDPOINT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfcsedev/ns-nfcsedev-_secure_element_endpoint_info) structures.