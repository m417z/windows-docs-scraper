# H245\_CAPABILITY enumeration

\[**H245\_CAPABILITY** is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **H245\_CAPABILITY** enum describes audio and video format support.

## Constants

**HC\_G711**

The G.711 audio protocol is supported.

**HC\_G723**

The G.723 audio protocol is supported.

**HC\_H263QCIF**

The H.263 video protocol is supported.

**HC\_H261QCIF**

The H.263 video protocol is supported.

## Requirements

| Requirement | Value |
|-------------------------|---------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.0 or later<br> |
| Header<br> | H323priv.h |

## See also

[**IH323LineEx::SetDefaultCapabilityPreferrence**](https://learn.microsoft.com/windows/win32/tapi/ih323lineex-setdefaultcapabilitypreferrence)

