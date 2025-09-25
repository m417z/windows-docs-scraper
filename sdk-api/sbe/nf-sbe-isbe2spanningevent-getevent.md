# ISBE2SpanningEvent::GetEvent

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an in-band spanning event and event data from the Stream Buffer Engine, version 2 (SBE2). An *in-band spanning event* is an event that exists until it is replaced or erased, and is part of the state for events that appear later in the same stream.

## Parameters

### `idEvt` [in]

GUID identifying the spanning event type.

### `streamId` [in]

Identifies the stream containing the spanning event.

### `pcb` [in, out]

Pointer to a value that gets the size of the event data buffer. If the *pb* parameter is **NULL**, this parameter returns the required buffer size.

### `pb` [out]

Pointer to a buffer that gets the event data. If this parameter is **NULL**, the *pcb* parameter returns the required buffer size. The structure of the event data depends on the event type.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The following types of in-band spanning events are defined.

| Value | Description |
| --- | --- |
| EVENTID_ARIBcontentSpanningEvent | Signals the start of Integrated Services Digital Broadcasting (ISDB) content. No data is associated with this event. |
| EVENTID_AudioDescriptorSpanningEvent | Contains an MPEG-2 descriptor for an audio stream. The event data is a byte array with the following layout:<br><br>* Byte 0 contains the descriptor tag.<br>* Byte 1 contains the length of the descriptor body.<br>* The remaining bytes contain the descriptor body. |
| EVENTID_AudioTypeSpanningEvent | Specifies the audio type of the data stream. The event data is a **char** that contains the audio_type field from the ISO 639 Language Descriptor. |
| EVENTID_CASFailureSpanningEvent | Signals a failure in the condition access system (CAS). The event data depends on the CAS technology in use. |
| EVENTID_ChannelChangeSpanningEvent | Signals the start or end of a channel change. The event data is a [ChannelChangeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/channelchangeinfo) structure. |
| EVENTID_ChannelInfoSpanningEvent | Contains information about the cable television channel. The event data is a [ChannelInfo](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/channelinfo) structure. |
| EVENTID_ChannelTypeSpanningEvent | Contains information about the cable television channel type. The event data is a [ChannelTypeInfo](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/channelinfo) structure. |
| EVENTID_CSDescriptorSpanningEvent | Contains a caption service descriptor. The event data is a [SpanningEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/spanningeventdescriptor) structure. |
| EVENTID_CtxADescriptorSpanningEvent | Contains a content advisory descriptor. The event data is a [SpanningEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/spanningeventdescriptor) structure. |
| EVENTID_DualMonoSpanningEvent | Specifies the audio languages for a dual-mono audio stream. The event data is a [DualMonoInfo](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/dualmonoinfo) structure. |
| EVENTID_DVBScramblingControlSpanningEvent | Indicates whether a Digital Video Broadcasting (DVB) program stream is scrambled. This event is signaled when the value of the transport_scrambling_control field changes. The event data is a [DVBScramblingControlSpanningEvent](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/dvbscramblingcontrolspanningevent) structure. |
| EVENTID_EmmMessageSpanningEvent | Contains information about an Entitlement Management Message (EMM) in a DVB data stream. The event data is a [SpanningEventEmmMessage](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/spanningeventemmmessage) structure. |
| EVENTID_LanguageSpanningEvent | Specifies the audio language. The event data is a [LanguageInfo](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/languageinfo) structure. |
| EVENTID_PBDAParentalControlSpanningEvent | Contains information about the current parental control policy. The event data is a [PBDAParentalControl](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/pbdaparentalcontrol) structure. |
| EVENTID_PIDListSpanningEvent | Contains a list of packet identifiers (PIDs) for the current stream. The event data is a [PIDListSpanningEvent](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/pidlistspanningevent) structure. |
| EVENTID_RRTSpanningEvent | Contains information about a rating region table (RRT). The data is a [SECTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-section) structure. |
| EVENTID_SignalAndServiceStatusSpanningEvent | Signals the current state of the television service. The event data is a member of the [SignalAndServiceStatusSpanningEvent_State](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/signalandservicestatusspanningevent-state) enumeration. |
| EVENTID_StreamIDSpanningEvent | Contains a stream identifier descriptor. The event data has the same format as the EVENTID_AudioDescriptorSpanningEvent event. |
| EVENTID_StreamTypeSpanningEvent | Specifies the stream type. The event data is a **DWORD** that contains a value from the [MPEG2StreamType](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/mpeg2streamtype) enumeration. |
| EVENTID_SubtitleSpanningEvent | Contains a subtitling descriptor. The event data has the same format as the **EVENTID_AudioDescriptorSpanningEvent** event. |
| EVENTID_TeletextSpanningEvent | Contains a teletext descriptor. The event data has the same format as the **EVENTID_AudioDescriptorSpanningEvent** event. |
| EVENTID_TuneFailureSpanningEvent | Signals a tuning failure. |

## See also

[ISBE2SpanningEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-isbe2spanningevent)

[ISBE2SpanningEvent::GetEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-isbe2spanningevent-getevent)