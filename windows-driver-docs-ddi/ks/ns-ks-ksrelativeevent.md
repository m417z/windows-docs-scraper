# KSRELATIVEEVENT structure

## Description

The [KSPROPERTY_CONNECTION_STARTAT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-startat) property is passed a KSRELATIVEEVENT structure.

## Members

### `Size`

Specifies the inclusive size of the structure, including any event specific data appended to the **EventData** member.

### `Flags`

Specifies what type of object is specified in the **ObjectHandle** and **ObjectPointer** union.

### `ObjectHandle`

Specifies the handle of the object supporting the event to be used if the **Flags** member contains the KSRELATIVEEVENT_FLAG_HANDLE flag.

### `ObjectPointer`

Specifies a pointer to the object supporting the event to be used if the Flags member contains the KSRELATIVEEVENT_FLAG_POINTER flag. This is valid only for kernel-mode clients.

### `Reserved`

Reserved and set to zero.

### `Event`

A [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) structure that contains the event to be used.

### `EventData`

A [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) structure that specifies the header for the event-specific data. The header itself is not actually used except as a starting point to access the event-specific data, and must be initialized to zero.