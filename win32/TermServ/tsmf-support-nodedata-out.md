# TSMF\_SUPPORT\_NODEDATA\_OUT structure

Used inside the [**TSMF\_SUPPORT\_DATA\_OUT**](https://learn.microsoft.com/windows/win32/termserv/tsmf-support-data-out) structure to contain information about supported media formats.

## Members

**nodeId**

The node.

**hrSupportStatus**

Whether the sink identified by the *clsidNewSink* parameter is supported.

The possible values are.

0

Not supported

1

Supported

Other values are undefined.

**clsidNewSink**

The sink associated with the media type.

**supportedMediaTypeIndex**

The zero-based index of the media type supported by the sink.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008 R2<br> |

## See also

[**QueryProperty**](https://learn.microsoft.com/windows/desktop/api/Wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-queryproperty)

[**TSMF\_SUPPORT\_DATA\_OUT**](https://learn.microsoft.com/windows/win32/termserv/tsmf-support-data-out)

