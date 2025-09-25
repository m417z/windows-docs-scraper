# EVENT_FIELD_TYPE enumeration

## Description

Defines the provider information to retrieve.

## Constants

### `EventKeywordInformation:0`

Keyword information defined in the manifest. For providers that define themselves using MOF classes, this type returns the enable flags values if the provider class includes the Flags property. For details, see the "Specifying level and enable flags values for a provider" section of [Event Tracing MOF Qualifiers](https://learn.microsoft.com/windows/desktop/ETW/event-tracing-mof-qualifiers).

### `EventLevelInformation`

Level information defined in the manifest.

### `EventChannelInformation`

Channel information defined in the manifest.

### `EventTaskInformation`

Task information defined in the manifest.

### `EventOpcodeInformation`

Operation code information defined in the manifest.

### `EventInformationMax`

Reserved.

## Remarks

If you specify **EventOpcodeInformation** when calling [TdhQueryProviderFieldInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhqueryproviderfieldinformation), you must specify the *EventFieldValue* parameter as follows:

* Bits 0 - 15 must contain the task value
* Bits 16 - 23 must contain the opcode value

You can get the task and opcode values from [EVENT_RECORD.EventHeader.EventDescriptor](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor).

WMI MOF class supports retrieving keyword and level information only.

## See also
[PROVIDER_FIELD_INFOARRAY](https://learn.microsoft.com/windows/desktop/api/tdh/ns-tdh-provider_field_infoarray)

[TdhEnumerateProviderFieldInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumerateproviderfieldinformation)

[TdhQueryProviderFieldInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhqueryproviderfieldinformation)