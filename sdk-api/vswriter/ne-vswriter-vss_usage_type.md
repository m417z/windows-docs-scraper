# VSS_USAGE_TYPE enumeration

## Description

The **VSS_USAGE_TYPE** enumeration specifies how
the host system uses the data managed by a writer involved in a VSS operation.

## Constants

### `VSS_UT_UNDEFINED:0`

The usage type is not known.

This indicates an error on the part of the writer.

### `VSS_UT_BOOTABLESYSTEMSTATE`

The data stored by the writer is part of the bootable system state.

### `VSS_UT_SYSTEMSERVICE`

The writer either stores data used by a system service or is a system service itself.

### `VSS_UT_USERDATA`

The data is user data.

### `VSS_UT_OTHER`

Unclassified data.

## Remarks

The usage type of the data that a writer manages is specified when it initializes its cooperation with the
shadow copy mechanism through
[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize).

Information about the usage type of the data that a writer manages can be retrieved through its metadata using
[IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity).

Requester applications that are interested in backing up system state should look for writers with the **VSS_UT_BOOTABLESYSTEMSTATE** or **VSS_UT_SYSTEMSERVICE** usage type.

## See also

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)

[VSS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_object_type)

[VSS_SOURCE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_source_type)