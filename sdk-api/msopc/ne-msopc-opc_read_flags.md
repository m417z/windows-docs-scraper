# OPC_READ_FLAGS enumeration

## Description

Describes the read settings for caching package components and validating them against *ECMA-376 OpenXML, 1st Edition, Part 2: Open Packaging Conventions (OPC)* conformance requirements.

## Constants

### `OPC_READ_DEFAULT:0`

Validate a package component against *OPC* conformance requirements when the component is accessed. For more information about *OPC* conformance validation, see Remarks.

When validation is performed on access, *OPC* validation errors can be returned by any method.

### `OPC_VALIDATE_ON_LOAD:0x1`

Validate all package components against *OPC* conformance requirements when a package is loaded. For more information about *OPC* conformance validation, see Remarks.

If this setting is enabled, performance costs for loading and validating package components are paid when the package is first loaded.

### `OPC_CACHE_ON_ACCESS:0x2`

Cache decompressed package component data as a temp file when accessing the component for the first time. When a package component is accessed repeatedly, this caching reduces overhead because the component data is decompressed one time for the first read instead of once for every read operation.

## Remarks

If both the **OPC_CACHE_ON_ACCESS** and **OPC_VALIDATE_ON_LOAD** read flags are set, all package components are decompressed and cached when a package is loaded.

The Packaging APIs do not use the *OPC* core properties feature; therefore, the core properties requirements listed in Table H-9 of the *OPC* are not validated by the Packaging APIs. For more information about *OPC* conformance requirements, see 1st edition, Part 2: Open Packaging Conventions in [ECMA-376 OpenXML](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/) (https://www.ecma-international.org/publications-and-standards/standards/ecma-376/).

**Important** Parts may be repeatedly read from the stream at any time, regardless of which read flags are set. For example, when a package is saved, previously accessed relationships in a Relationships part in the original package may be accessed again to preserve markup compatibility.

## See also

[ECMA-376 OpenXML standard](https://www.ecma-international.org/publications-and-standards/standards/ecma-376/)

**External Resources**

[Getting Started with the Packaging API](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-api-overview)

[IOpcFactory::ReadPackageFromStream](https://learn.microsoft.com/previous-versions/windows/desktop/api/msopc/nf-msopc-iopcfactory-readpackagefromstream)

**Overviews**

[Packaging API Programming Guide](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-guide)

[Packaging API Samples](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-programming-samples)

[Packaging Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/opc/packaging-enumerations)

[Packaging Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd371635(v=vs.85))

**Reference**