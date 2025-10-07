# TSMF\_SUPPORT\_NODEDATA\_IN structure

Used inside the [**TSMF\_SUPPORT\_DATA\_IN**](https://learn.microsoft.com/windows/win32/termserv/tsmf-support-data-in) structure to contain information about supported media formats.

## Members

**byteCount**

The size of the structure in bytes.

**nodeId**

The node.

**numMediaTypes**

The number of media format structures.

**...**

A variable number of structures defining audio or video media formats. The **FormatType** is either **FORMAT\_WaveFormatEx** for audio or **FORMAT\_MFVideoFormat** for video.

For details of this structure, see [TS\_AM\_MEDIA\_TYPE Structure](https://learn.microsoft.com/openspecs/windows_protocols/ms-rdpev/22a57950-042e-48bd-8135-3580f3a3f934).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------|
| Minimum supported client<br> | None supported<br> |
| Minimum supported server<br> | Windows Server 2008 R2<br> |

## See also

[**QueryProperty**](https://learn.microsoft.com/windows/desktop/api/Wtsprotocol/nf-wtsprotocol-iwrdsprotocolconnection-queryproperty)

[**TSMF\_SUPPORT\_DATA\_IN**](https://learn.microsoft.com/windows/win32/termserv/tsmf-support-data-in)

