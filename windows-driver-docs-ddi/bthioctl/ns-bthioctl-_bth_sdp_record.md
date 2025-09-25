# _BTH_SDP_RECORD structure

## Description

The BTH_SDP_RECORD structure contains information about an SDP record that is to be added to the
local SDP server.

## Members

### `fSecurity`

A combination of flags that specifies the security attributes of the SDP record. Valid flag values
are listed in the following table.

| Flag | Description |
| --- | --- |
| SERVICE_SECURITY_AUTHENTICATE | Only authenticated clients can access this record. |
| SERVICE_SECURITY_AUTHORIZE | Only authorized clients can access this record. |
| SERVICE_SECURITY_ENCRYPT_OPTIONAL | Encryption is optional to access this record. |
| SERVICE_SECURITY_ENCRYPT_REQUIRED | Encryption is required to access this record. |
| SERVICE_SECURITY_NONE | No security is required to access this record. |

### `fOptions`

A combination of flags that specifies the publication options for the SDP record. Valid flag
values are listed in the following table.

| Flag | Description |
| --- | --- |
| SERVICE_OPTION_DO_NOT_PUBLISH | The record should be entered into the local SDP server, but should not be published to remote systems. |
| SERVICE_OPTION_NO_PUBLIC_BROWSE | The record should be obtainable if specifically requested, but it should not be browseable using SDP browse groups. |

### `fCodService`

###### Possible values include:

#### COD_SERVICE_AUDIO

#### COD_SERVICE_CAPTURING

#### COD_SERVICE_INFORMATION

#### COD_SERVICE_LIMITED

#### COD_SERVICE_NETWORKING

#### COD_SERVICE_OBJECT_XFER

#### COD_SERVICE_POSITIONING

#### COD_SERVICE_RENDERING

#### COD_SERVICE_TELEPHONY

### `recordLength`

The size, in bytes, of the record.

### `record`

 The SDP record in its raw stream format. The first byte is defined in this structure, with the
entire record following it.

## Remarks

This structure is passed as the input buffer and output buffer of
[IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record_with_info).

## See also

[IOCTL_BTH_SDP_SUBMIT_RECORD_WITH_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthioctl/ni-bthioctl-ioctl_bth_sdp_submit_record_with_info)