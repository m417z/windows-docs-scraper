# _DXGK_DIAGNOSTIC_HEADER structure

## Description

Header structure which contains the common fields used to describe all diagnostic events.

## Members

### `Size`

Size in bytes of the event being reported including the header. For OS defined event types, the size will be checked against the expected size of the associated structure.

### `Reserved`

Reserved.

### `Value`

Value of the header.

### `TargetId`

A 32-bit value that identifies the component to which this event relates. The interpretation of the field is dependent on the type of diagnostic being reported.

### `SourceId`

A 32-bit value that identifies the component to which this event relates. The interpretation of the field is dependent on the type of diagnostic being reported.

### `Id`

A 32-bit value that identifies the component to which this event relates. The interpretation of the field is dependent on the type of diagnostic being reported.

### `Category`

A [DXGK_DIAGNOSTIC_CATEGORIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_categories) structure with a single bit field set to one to indicate the category of diagnostic being described.

### `Type`

A [DXGK_DIAGNOSTIC_TYPES](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_diagnostic_types) structure with a single bit field set to one to indicate the type of diagnostic being described.

### `SequenceNumber`

An adapter global value incremented for each diagnostic reported such that each report has a unique sequence number, within the limits of a 32-bit value.