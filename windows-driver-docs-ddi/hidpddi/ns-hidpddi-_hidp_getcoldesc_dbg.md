# _HIDP_GETCOLDESC_DBG structure

## Description

Contains the error code indicating the failure in parsing the report
descriptor. This structure is used in the [HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription) call.

## Members

### `BreakOffset`

The byte offset in the report descriptor where the parsing error occurred.

### `ErrorCode`

Indicates the parsing error, if it’s not HIDP_GETCOLDESC_SUCCESS.

All possible values are defined in hidpddi.h, from HIDP_GETCOLDESC_SUCCESS to the end of the file.

### `Args`

Error-specific arguments. These are described as comments in the possible values for **ErrorCode** in hidpddi.h.

## See also

[HidP_GetCollectionDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpddi/nf-hidpddi-hidp_getcollectiondescription)