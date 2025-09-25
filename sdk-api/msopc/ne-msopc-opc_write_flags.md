# OPC_WRITE_FLAGS enumeration

## Description

Describes the encoding method that is used by the serialization object to produce the package.

## Constants

### `OPC_WRITE_DEFAULT:0`

Use Zip64 encoding. The minimum software version for extracting a package with Zip64 encoding is 4.5.

### `OPC_WRITE_FORCE_ZIP32:0x1`

Force Zip32 encoding. The minimum software version for extracting a package with Zip32 encoding is 2.0.

If one or more of the following Zip32 limitations are violated, the package write will fail:

* The maximum size for a single, uncompressed file item is 4 gigabytes.
* The maximum number of file items is 65535 (2¹⁶-1).

## See also

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory::WritePackageToStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-writepackagetostream)

[Open Packaging Conventions Fundamentals](https://learn.microsoft.com/previous-versions/windows/desktop/opc/open-packaging-conventions-overview)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**

[Relationships Overview](https://learn.microsoft.com/previous-versions/windows/desktop/opc/relationships-overview)