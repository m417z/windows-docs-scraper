# MFNETSOURCE_PROTOCOL_TYPE enumeration

## Description

Indicates the type of control protocol that is used in streaming or downloading.

## Constants

### `MFNETSOURCE_UNDEFINED:0`

The protocol type has not yet been determined.

### `MFNETSOURCE_HTTP:0x1`

The protocol type is HTTP. This includes HTTPv9, WMSP, and HTTP download.

### `MFNETSOURCE_RTSP:0x2`

The protocol type is Real Time Streaming Protocol (RTSP).

### `MFNETSOURCE_FILE:0x3`

The content is read from a file. The file might be local or on a remote share.

### `MFNETSOURCE_MULTICAST:0x4`

The protocol type is multicast.

**Note** Requires Windows 7 or later.

## See also

[IMFNetSchemeHandlerConfig::GetSupportedProtocolType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetschemehandlerconfig-getsupportedprotocoltype)

[MFNETSOURCE_STATISTICS_IDS](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetsource_statistics_ids)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Supported Protocols](https://learn.microsoft.com/windows/desktop/medfound/supported-protocols)