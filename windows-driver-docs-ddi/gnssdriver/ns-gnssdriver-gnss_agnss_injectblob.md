## Description

The **GNSS_AGNSS_INJECTBLOB** structure defines the format for AGNSS extended ephemeris injection.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `BlobOui`

This field indicates the 3-byte OUI of silicon vendor or device maker.

### `BlobVersion`

Version of the blob from the same vendor.

### `AgnssFormat`

Data format of the blob.

The formats are defined as macros (GNSS_AGNSSFORMAT_*).

### `BlobSize`

Size of the blob data in bytes.

### `BlobData`

This field defines the start of the blob data.

The structure only contains the first byte of the blob data. The rest of the blob data is saved right after the structure in the memory. The size of the blob is indicated by BlobSize.