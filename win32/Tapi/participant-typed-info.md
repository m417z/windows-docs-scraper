# PARTICIPANT\_TYPED\_INFO enumeration

\[**PARTICIPANT\_TYPED\_INFO** is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The members of the **PARTICIPANT\_TYPED\_INFO** enum identify the type of participant information being retrieved by the [**ITParticipant::get\_ParticipantTypedInfo**](https://learn.microsoft.com/windows/win32/tapi/itparticipant-get-participanttypedinfo) method. This enum is used by applications that access the [IPConf MSP](https://learn.microsoft.com/windows/win32/tapi/ipconf-msp).

## Constants

**PTI\_CANONICALNAME**

Canonical name of participant, such as someone@example.com.

**PTI\_NAME**

Displayable name of participant.

**PTI\_EMAILADDRESS**

Participant's email address.

**PTI\_PHONENUMBER**

Participant's phone address.

**PTI\_LOCATION**

Participant's geographical address.

**PTI\_TOOL**

Participant's application.

**PTI\_NOTES**

Notes concerning participant.

**PTI\_PRIVATE**

Defines an experimental or application-specific Source Description (SDES) extension. See RFC 1889 for details.

## Requirements

| Requirement | Value |
|-------------------------|---------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.0 or later<br> |
| Header<br> | Confpriv.h |

## See also

[**ITParticipant::get\_ParticipantTypedInfo**](https://learn.microsoft.com/windows/win32/tapi/itparticipant-get-participanttypedinfo)

[IPConf MSP](https://learn.microsoft.com/windows/win32/tapi/ipconf-msp)

[IPConf MSP Interfaces](https://learn.microsoft.com/windows/win32/tapi/ipconf-msp-interfaces)

