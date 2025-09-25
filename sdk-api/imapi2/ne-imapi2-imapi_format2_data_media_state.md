# IMAPI_FORMAT2_DATA_MEDIA_STATE enumeration

## Description

Defines values for the possible media states.

## Constants

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_UNKNOWN:0`

Indicates that the interface does not know the media state.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_INFORMATIONAL_MASK:0xf`

Reports information (but not errors) about the media state.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_UNSUPPORTED_MASK:0xfc00`

Reports an unsupported media state.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_OVERWRITE_ONLY:0x1`

Write operations can occur on used portions of the disc.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_RANDOMLY_WRITABLE:0x1`

Media is randomly writable. This indicates that a single session can be written to this disc.

**Note** This value is deprecated and superseded by **IMAPI_FORMAT2_DATA_MEDIA_STATE_OVERWRITE_ONLY**.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_BLANK:0x2`

Media has never been used, or has been erased.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_APPENDABLE:0x4`

Media is appendable (supports multiple sessions).

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_FINAL_SESSION:0x8`

Media can have only one additional session added to it, or the media does not support multiple sessions.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_DAMAGED:0x400`

Media is not usable by this interface. The media might require an erase or other recovery.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_ERASE_REQUIRED:0x800`

Media must be erased prior to use by this interface.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_NON_EMPTY_SESSION:0x1000`

Media has a partially written last session, which is not supported by this interface.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_WRITE_PROTECTED:0x2000`

Media or drive is write-protected.

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_FINALIZED:0x4000`

Media cannot be written to (finalized).

### `IMAPI_FORMAT2_DATA_MEDIA_STATE_UNSUPPORTED_MEDIA:0x8000`

Media is not supported by this interface.

## Remarks

This enumeration should be treated as a bitmask. Nearly all of the values set one bit set to one and the other bits to zero. Three exceptions to this rule were added: unknown, unsupported media mask, and informational mask. For example, to test for unsupported media, check the value against IMAPI_FORMAT2_DATA_MEDIA_STATE_UNSUPPORTED_MASK.

## See also

[IDiscFormat2Data::get_CurrentMediaStatus](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-get_currentmediastatus)