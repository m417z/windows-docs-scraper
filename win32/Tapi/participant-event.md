# PARTICIPANT\_EVENT enumeration

\[ This enumeration is not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API provides similar functionality.\]

The **PARTICIPANT\_EVENT** enum describes participant events. The [**ITParticipantEvent::get\_Event**](https://learn.microsoft.com/windows/win32/tapi/itparticipantevent-get-event) method returns a member of this enum to indicate the type of conference participant event that occurred. This enum is used by applications that access the [IPConf MSP](https://learn.microsoft.com/windows/win32/tapi/ipconf-msp).

## Constants

**PE\_NEW\_PARTICIPANT**

A new participant has been added to the conference.

**PE\_INFO\_CHANGE**

Information on a participant has changed.

**PE\_PARTICIPANT\_LEAVE**

A participant has left the conference.

**PE\_NEW\_SUBSTREAM**

A new substream has been added to the participant.

**PE\_SUBSTREAM\_REMOVED**

A new substream has been removed from the participant.

**PE\_SUBSTREAM\_MAPPED**

A participant has been mapped to a substream.

**PE\_SUBSTREAM\_UNMAPPED**

A participant has been unmapped from a substream.

**PE\_PARTICIPANT\_TIMEOUT**

A participant has been removed from the conference due to a timeout.

**PE\_PARTICIPANT\_RECOVERED**

A removed participant is again visible. Usually, this is a participant who timed out but signals are now being received.

**PE\_PARTICIPANT\_ACTIVE**

The participant has become active in the conference.

**PE\_PARTICIPANT\_INACTIVE**

The participant has become inactive in the conference.

**PE\_LOCAL\_TALKING**

The local participant has started to talk.

**PE\_LOCAL\_SILENT**

The local participant has become silent in the conference.

## Requirements

| Requirement | Value |
|-------------------------|------------------------------------------------------------------------------------|
| TAPI version<br> | Requires TAPI 3.0 or later<br> |
| Header<br> | Ipmsp.h |

## See also

[**ITParticipantEvent::get\_Event**](https://learn.microsoft.com/windows/win32/tapi/itparticipantevent-get-event)

[IPConf MSP](https://learn.microsoft.com/windows/win32/tapi/ipconf-msp)

[IPConf MSP Interfaces](https://learn.microsoft.com/windows/win32/tapi/ipconf-msp-interfaces)

