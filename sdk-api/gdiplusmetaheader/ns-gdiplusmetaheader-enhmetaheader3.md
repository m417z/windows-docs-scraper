# ENHMETAHEADER3 structure

## Description

The **ENHMETAHEADER3** structure contains enhanced-metafile data including the dimensions of the metafile image, the number of records in the metafile, and the resolution of the device on which the metafile was created.

## Members

### `iType`

Type: **DWORD**

Record type. Value is always EMR_HEADER.

### `nSize`

Type: **DWORD**

Structure size, in bytes. This may be greater than the value returned by **sizeof**(**ENHMETAHEADER3**).

### `rclBounds`

Type: **RECTL**

Bounding rectangle, in device units, for the image stored in the metafile.

### `rclFrame`

Type: **RECTL**

Rectangle, in 0.01 millimeter units, that surrounds the image stored in the metafile.

### `dSignature`

Type: **DWORD**

Must be ENHMETA_SIGNATURE.

### `nVersion`

Type: **DWORD**

Version number of the metafile format. The current version is 0x10000.

### `nBytes`

Type: **DWORD**

Size, in bytes, of the metafile.

### `nRecords`

Type: **DWORD**

Number of records in the metafile.

### `nHandles`

Type: **WORD**

Number of handles in the metafile handle table. Handle index zero is reserved.

### `sReserved`

Type: **WORD**

Reserved. Must be zero.

### `nDescription`

Type: **DWORD**

Number of characters in the string that contains the description of the metafile's contents. This member is 0 if the metafile does not have a description string.

### `offDescription`

Type: **DWORD**

Offset from the beginning of the **ENHMETAHEADER3** structure to the string that contains the description of the metafile's contents. This member is 0 if the metafile does not have a description string.

### `nPalEntries`

Type: **DWORD**

Number of entries in the metafile palette.

### `szlDevice`

Type: **SIZEL**

Resolution, in pixels, of the reference device.

### `szlMillimeters`

Type: **SIZEL**

Resolution, in millimeters, of the reference device.