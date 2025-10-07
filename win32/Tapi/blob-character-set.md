# BLOB\_CHARACTER\_SET enumeration

\[ Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **BLOB\_CHARACTER\_SET** enum indicates the character set used by the current conference blob.

## Constants

**BCS\_ASCII**

Standard ASCII format.

**BCS\_UTF7**

Seven-bit transformation format of Unicode. For details on this format, conduct an Internet search for RFC 1642.

**BCS\_UTF8**

UCS Transformation Format 8. For details on this format, conduct an Internet search for ISO (the International Organization for Standardization) and IEC (the International Electrotechnical Commission) document ISO/IEC JTC1/SC2/WG2 N 1036, dated August 1, 1994, by WG2 Project Editor.

## Requirements

| Requirement | Value |
|-------------------------|-------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.0 or later<br> |
| Header<br> | Sdpblb.h |

## See also

[**ITDirectoryObjectConference**](https://learn.microsoft.com/windows/desktop/api/Rend/nn-rend-itdirectoryobjectconference)

[**get\_CharacterSet**](https://learn.microsoft.com/windows/win32/tapi/itconferenceblob-get-characterset)

[**Init**](https://learn.microsoft.com/windows/win32/tapi/itconferenceblob-init)

[**SetConferenceBlob**](https://learn.microsoft.com/windows/win32/tapi/itconferenceblob-setconferenceblob)

