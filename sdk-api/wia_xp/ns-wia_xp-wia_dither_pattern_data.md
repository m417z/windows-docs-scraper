# WIA_DITHER_PATTERN_DATA structure

## Description

The **WIA_DITHER_PATTERN_DATA** structure specifies a dither pattern for scanners. It is used in conjunction with the [scanner device property constant](https://learn.microsoft.com/windows/desktop/wia/-wia-wiaitempropscannerdevice) WIA_DPS_DITHER_PATTERN_DATA.

## Members

### `lSize`

Type: **LONG**

Specifies the size of this structure in bytes. Should be set to **sizeof(WIA_DITHER_PATTERN_DATA)**.

### `bstrPatternName`

Type: **BSTR**

Specifies a string that contains the name of this dither pattern.

### `lPatternWidth`

Type: **LONG**

Indicates the width of the dither pattern in bytes.

### `lPatternLength`

Type: **LONG**

Indicates the length of the dither pattern in bytes.

### `cbPattern`

Type: **LONG**

Specifies the total number of bytes in the array pointed to by the **pbPattern** member.

### `pbPattern`

Type: **BYTE***

Specifies a pointer to a buffer that contains the dither pattern.