## Description

The **WheaErrorRecordBuilderAddSection** function finds the next section, initializes its descriptor, and returns a pointer for the caller to populate with data.

## Parameters

### `Record` [in, out]

Supplies a buffer that contains the error record data.

### `MaxSectionCount` [in]

Defines the **UINT32** parameter *MaxSectionCount*.

### `SectionLength` [in]

Supplies a length for the new section to be added.

### `Flags` [in]

Supplies the flags for the section.

### `SectionType` [in]

Supplies the GUID to identify the section.

### `DescriptorOut` [in, out, optional]

Supplies an optional buffer to get the section descriptor if additional information needs to be added.

## Return value

A pointer to the next available space for error record information. Returns NULL if the record buffer is full.

## Remarks

## See also