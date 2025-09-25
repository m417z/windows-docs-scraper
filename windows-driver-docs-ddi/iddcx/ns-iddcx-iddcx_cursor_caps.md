# IDDCX_CURSOR_CAPS structure

## Description

 Gives information about the capabilities of the cursor.

## Members

### `Size`

 Total size of the structure.

### `ColorXorCursorSupport`

 Indicates what level of support the driver has for XOR masks in the 32-bit masked color cursor format.

**Note** The OS first converts any monochrome cursor to a color mask cursor.

### `AlphaCursorSupport`

 Indicates if the adapter supports the 32-bit alpha cursor format. Most cursors are alpha format.

### `MaxX`

 The maximum width supported for all supported cursor types.

### `MaxY`

 The maximum height support for all cursor types.