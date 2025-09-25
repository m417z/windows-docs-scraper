# OPC_STREAM_IO_MODE enumeration

## Description

Describes the read/write status of a stream.

## Constants

### `OPC_STREAM_IO_READ:1`

Creates a read-only stream for loading an existing package.

### `OPC_STREAM_IO_WRITE:2`

Creates a write-only stream for saving a new package.

## Remarks

**Important**

Reading and writing to the same package is not recommended and may result in undefined behavior.

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory::CreateStreamOnFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-createstreamonfile)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**