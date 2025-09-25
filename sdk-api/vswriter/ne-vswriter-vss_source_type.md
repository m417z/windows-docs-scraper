# VSS_SOURCE_TYPE enumeration

## Description

The **VSS_SOURCE_TYPE** enumeration specifies the
type of data that a writer manages.

## Constants

### `VSS_ST_UNDEFINED:0`

The source of the data is not known.

This indicates a writer error, and the requester should report it.

### `VSS_ST_TRANSACTEDDB`

The source of the data is a database that supports transactions, such as Microsoft SQL Server.

### `VSS_ST_NONTRANSACTEDDB`

The source of the data is a database that does not support transactions.

### `VSS_ST_OTHER`

Unclassified source type—data will be in a file group.

This is the default source type.

## Remarks

The source type of the data that a writer manages is specified when it initializes its cooperation with the
shadow copy mechanism through a call to
[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize).

Information about the source type of the data that a writer manages can be retrieved through its metadata
using
[IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity).

## See also

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[IVssExamineWriterMetadata::GetIdentity](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getidentity)

[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type)

[VSS_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_object_type)

[VSS_USAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_usage_type)