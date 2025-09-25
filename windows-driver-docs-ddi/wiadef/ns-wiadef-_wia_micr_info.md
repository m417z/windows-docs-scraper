# _WIA_MICR_INFO structure

## Description

The **WIA_MICR_INFO** structure stores information for one decoded MICR code.

## Members

### `Size`

The total size of this structure, in bytes.

### `Page`

The page number where the MICR code was detected. A zero-based index referring to the current scan job.

### `Length`

Length of the MICR text, in characters, excluding the length of the NULL terminator.

### `Text`

Placeholder for a NULL terminated character string containing the MICR text.