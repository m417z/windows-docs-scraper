# VSS_ALTERNATE_WRITER_STATE enumeration

## Description

The **VSS_ALTERNATE_WRITER_STATE** enumeration
is used to indicate whether a given writer has an associated alternate writer. The existence
of an alternate writer is set during writer initialization by
[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize).

Currently, the only supported value for a method taking a
**VSS_ALTERNATE_WRITER_STATE** argument is
**VSS_AWS_NO_ALTERNATE_WRITER**.

## Constants

### `VSS_AWS_UNDEFINED:0`

No information is available as to the existence of an alternate writer. This value indicates an application
error. This enumeration value is reserved for future use.

### `VSS_AWS_NO_ALTERNATE_WRITER`

A given writer does not have an alternate writer.

### `VSS_AWS_ALTERNATE_WRITER_EXISTS`

An alternate writer exists. This alternate writer runs when the writer is not available. This enumeration
value is reserved for future use.

### `VSS_AWS_THIS_IS_ALTERNATE_WRITER`

The writer in question is an alternate writer. This enumeration value is reserved for future use.

## See also

[CVssWriter::Initialize](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-initialize)

[CVssWriter::OnVSSApplicationStartup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onvssapplicationstartup)

[VSS_WRITER_STATE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_writer_state)