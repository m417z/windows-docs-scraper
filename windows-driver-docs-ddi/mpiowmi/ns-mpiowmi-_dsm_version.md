# _DSM_VERSION structure

## Description

The DSM_VERSION structure represents version information that is associated with a DSM binary or package. While this assumes that a DSM's version will be of the type MajorVersion.MinorVersion.ProductBuild.QfeNumber, it is not mandatory for the DSM to follow this convention. The DSM must, however, fill in zeros for the fields its does not support.

## Members

### `MajorVersion`

An unsigned 32-bitfield that represents the major version portion of the version.

### `MinorVersion`

An unsigned 32-bitfield that represents the minor version portion of the version.

### `ProductBuild`

An unsigned 32-bitfield that represents the product build portion of the version.

### `QfeNumber`

An unsigned 32-bitfield that represents the QFE number portion of the version.