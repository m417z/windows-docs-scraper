# MFNETSOURCE_STATISTICS_IDS enumeration

## Description

Defines statistics collected by the network source. The values in this enumeration define property identifiers (PIDs) for the [MFNETSOURCE_STATISTICS](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-statistics-property) property.

To retrieve statistics from the network source, call [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice) with the service identifier **MFNETSOURCE_STATISTICS_SERVICE** and the interface identifier IID_IPropertyStore. The retrieved pointer is an **IPropertyStore** pointer. To get the value of a network statistic, construct a **PROPERTYKEY** with **fmtid** equal to **MFNETSOURCE_STATISTICS** and **pid** equal to a value from this enumeration. Then call **IPropertyStore::GetValue** with the property key to retrieve the value of the statistic as a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant).

In the descriptions that follow, the data type and value-type tag for the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) are listed in parentheses.

## Constants

### `MFNETSOURCE_RECVPACKETS_ID:0`

The number of packets received (**LONG**, **VT_I4**).

### `MFNETSOURCE_LOSTPACKETS_ID`

The number of packets lost (**LONG**, **VT_I4**).

### `MFNETSOURCE_RESENDSREQUESTED_ID`

The number of requests to resend packets (**LONG**, **VT_I4**).

### `MFNETSOURCE_RESENDSRECEIVED_ID`

The number of resent packets received (**LONG**) (**VT_I4**).

### `MFNETSOURCE_RECOVEREDBYECCPACKETS_ID`

The total number of packets recovered by error correction (**LONG**, **VT_I4**).

### `MFNETSOURCE_RECOVEREDBYRTXPACKETS_ID`

The total number of packets recovered by retransmission (**LONG**, **VT_I4**).

### `MFNETSOURCE_OUTPACKETS_ID`

The total number of packets returned to user, including recovered packets (**LONG**, **VT_I4**).

### `MFNETSOURCE_RECVRATE_ID`

The 10-second average receiving rate (**LONG**, **VT_I4**).

### `MFNETSOURCE_AVGBANDWIDTHBPS_ID`

The average bandwidth of the clip (**LONG**, **VT_I4**).

### `MFNETSOURCE_BYTESRECEIVED_ID`

The total number of bytes received (**ULONGLONG**, **VT_UI8**).

### `MFNETSOURCE_PROTOCOL_ID`

The type of control protocol used to receive the data (**LONG**, **VT_I4**). The value is a member of the [MFNETSOURCE_PROTOCOL_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetsource_protocol_type) enumeration.

### `MFNETSOURCE_TRANSPORT_ID`

The type of control protocol used to receive the data (**LONG**, **VT_I4**). The value is a member of the [MFNETSOURCE_TRANSPORT_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetsource_transport_type) enumeration.

### `MFNETSOURCE_CACHE_STATE_ID`

The status of cache for a media file or entry (**LONG**, **VT_I4**). The value is a member of the [MFNETSOURCE_CACHE_STATE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfnetsource_cache_state) enumeration.

### `MFNETSOURCE_LINKBANDWIDTH_ID`

The current link bandwidth, in bits per second (**LONG**, **VT_I4**).

### `MFNETSOURCE_CONTENTBITRATE_ID`

The current bit rate of the content (**LONG**, **VT_I4**).

### `MFNETSOURCE_SPEEDFACTOR_ID`

The negotiated speed factor used in data transmission (**LONG**, **VT_I4**). The sender transmits data at the rate of the speed factor multiplied by the bit rate of the content.

### `MFNETSOURCE_BUFFERSIZE_ID`

The playout buffer size, in milliseconds (**LONG**, **VT_I4**).

### `MFNETSOURCE_BUFFERPROGRESS_ID`

The percentage of the playout buffer filled during buffering. The value is an integer in the range 0–100. (**LONG**, **VT_I4**).

### `MFNETSOURCE_LASTBWSWITCHTS_ID`

The number of ticks since the last bandwidth switch (**LONG**, **VT_I4**).

### `MFNETSOURCE_SEEKRANGESTART_ID`

The start of the seekable range, in 100-nanosecond units (**ULONGLONG**, **VT_UI8**).

### `MFNETSOURCE_SEEKRANGEEND_ID`

The end of the seekable range, in 100-nanosecond units (**ULONGLONG**, **VT_UI8**).

### `MFNETSOURCE_BUFFERINGCOUNT_ID`

The number of times buffering has occurred, including the initial buffering (**LONG**, **VT_I4**).

### `MFNETSOURCE_INCORRECTLYSIGNEDPACKETS_ID`

The number of packets that had incorrect signatures (**LONG**, **VT_I4**).

### `MFNETSOURCE_SIGNEDSESSION_ID`

Boolean value indicating whether the current session is signed (**VARIANT_BOOL**, **VT_BOOL**).

### `MFNETSOURCE_MAXBITRATE_ID`

The current maximum bit rate of the content (**LONG**, **VT_I4**).

### `MFNETSOURCE_RECEPTION_QUALITY_ID`

The reception quality (**LONG**, **VT_I4**).

### `MFNETSOURCE_RECOVEREDPACKETS_ID`

The total number of recovered packets (**LONG**, **VT_I4**).

### `MFNETSOURCE_VBR_ID`

Boolean value indicating whether the content has a variable bit rate (**VARIANT_BOOL**, **VT_BOOL**).

### `MFNETSOURCE_DOWNLOADPROGRESS_ID`

The percentage of the content that has been downloaded. The value is an integer in the range 0–100. (**LONG**, **VT_I4**).

### `MFNETSOURCE_UNPREDEFINEDPROTOCOLNAME_ID`

## See also

[Client Logging](https://learn.microsoft.com/windows/desktop/medfound/client-logging)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)