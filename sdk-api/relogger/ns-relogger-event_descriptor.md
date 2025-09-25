# EVENT_DESCRIPTOR structure

## Description

The **EVENT_DESCRIPTOR** structure contains metadata that defines the event.

## Members

### `Id`

The event identifier.

### `Version`

The version of the event. The version indicates a revision to the event definition. You can use this member and the Id member to uniquely identify the event within the scope of a provider.

### `Channel`

The audience for the event (for example, administrator or developer).

### `Level`

The severity or level of detail included in the event (for example, informational or fatal).

### `Opcode`

A step in a sequence of operations being performed within the Task.

### `Task`

A larger unit of work within an application or component (is broader than the Opcode).

### `Keyword`

A bitmask that specifies a logical group of related events. Each bit corresponds to one group. An event may belong to one or more groups. The keyword can contain one or more provider-defined keywords, standard keywords, or both.

## Remarks

This structure represents an event defined in the manifest. You do not declare and populate this structure, instead you use the [Message Compiler (MC.exe)](https://learn.microsoft.com/windows/desktop/WES/message-compiler--mc-exe-) to generate a header file that declares and populates this structure for each event in the manifest. For details on writing the manifest and generating the header file, see [Writing an Instrumentation Manifest](https://learn.microsoft.com/windows/desktop/WES/writing-an-instrumentation-manifest) and [Compiling an Instrumentation Manifest](https://learn.microsoft.com/windows/desktop/WES/compiling-an-instrumentation-manifest).

For details on the members of this structure, see the attributes of the [EventDefinitionType](https://learn.microsoft.com/windows/desktop/WES/eventmanifestschema-eventdefinitiontype-complextype) complex type.

 You specify this structure when calling [EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite) or [EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer) to write the event. You can also use it when calling [EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled) to determine if you should write the event.

This structure is also included in the [EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header) structure that is returned with the event record when you consume events using the [EventRecordCallback](https://learn.microsoft.com/windows/desktop/ETW/eventrecordcallback) callback. For MOF-defined events, the **Opcode** member contains the event type value. The **Version** and **Level** members contain the expected information.

## See also

[EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header)

[EventDescCreate](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdesccreate)

[EventDescGetChannel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetchannel)

[EventDescGetId](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetid)

[EventDescGetKeyword](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetkeyword)

[EventDescGetLevel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetlevel)

[EventDescGetOpcode](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetopcode)

[EventDescGetTask](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgettask)

[EventDescGetVersion](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescgetversion)

[EventDescOrKeyword](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescorkeyword)

[EventDescSetChannel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetchannel)

[EventDescSetId](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetid)

[EventDescSetKeyword](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetkeyword)

[EventDescSetLevel](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetlevel)

[EventDescSetOpcode](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetopcode)

[EventDescSetTask](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsettask)

[EventDescSetVersion](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdescsetversion)

[EventDescZero](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdesczero)

[EventEnabled](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventenabled)

[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite)

[EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer)

[PROVIDER_EVENT_INFO](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_event_info)

[TdhEnumerateManifestProviderEvents](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumeratemanifestproviderevents)

[TdhGetManifestEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetmanifesteventinformation)