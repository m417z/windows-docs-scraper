# PROVIDER_EVENT_INFO structure

## Description

The **PROVIDER_EVENT_INFO** structure defines an array of events in a provider manifest.

## Members

### `NumberOfEvents`

The number of elements in the **EventDescriptorsArray** array.

### `Reserved`

Reserved.

### `EventDescriptorsArray`

An array of [EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor) structures that contain information about each event.

## See also
[EVENT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/evntprov/ns-evntprov-event_descriptor)

[TdhEnumerateManifestProviderEvents](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhenumeratemanifestproviderevents)

[TdhGetManifestEventInformation](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhgetmanifesteventinformation)