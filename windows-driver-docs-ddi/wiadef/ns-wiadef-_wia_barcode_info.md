## Description

The **WIA_BARCODE_INFO** structure stores information for one decoded barcode.

## Members

### `Size`

The total size of this structure, in bytes.

### `Type`

The barcode type. One of the [WIA_IPS_SUPPORTED_BARCODE_TYPES](https://learn.microsoft.com/windows-hardware/drivers/image/wia-ips-supported-barcode-types) values.

### `Page`

The page number where the barcode was detected. A zero-based index referring to the current scan job.

### `Confidence`

The confidence level. A value in the range from 0 (no confidence) to 10 (maximum confidence).

### `XOffset`

The horizontal coordinate, in pixels (relative to the scanned image), where the top-left origin of the barcode was detected. This value can be 0 if it is unknown.

### `YOffset`

The vertical coordinate, in pixels (relative to the scanned image), where the top-left origin of the barcode was detected. This value can be 0 if it is unknown.

### `Rotation`

The rotation of the barcode, in degrees. A value in the rage from 0 to 359. This value can be 0 if it is unknown.

### `Length`

The number of text characters in the character string containing the decoded barcode text, excluding the length of the NULL terminator.

### `Text`

Placeholder for the character string containing the decoded barcode text (double byte characters, NULL terminated).