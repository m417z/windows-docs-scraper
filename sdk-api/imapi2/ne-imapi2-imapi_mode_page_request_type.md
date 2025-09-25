# IMAPI_MODE_PAGE_REQUEST_TYPE enumeration

## Description

Defines values that indicate requests sent to a device using the MODE_SENSE10 MMC command.

## Constants

### `IMAPI_MODE_PAGE_REQUEST_TYPE_CURRENT_VALUES:0`

Requests current settings of the mode page. This is the most common request type, and the most commonly supported type of this command.

### `IMAPI_MODE_PAGE_REQUEST_TYPE_CHANGEABLE_VALUES:1`

Requests a mask that indicates settings that are write enabled. A write-enabled setting has a corresponding bit that is set to one in the mask. A read-only setting has a corresponding bit that is set to zero in the mask .

### `IMAPI_MODE_PAGE_REQUEST_TYPE_DEFAULT_VALUES:2`

Requests the power-on settings of the drive.

### `IMAPI_MODE_PAGE_REQUEST_TYPE_SAVED_VALUES:3`

Requests a saved configuration for a drive. This functionality might not be supported on all devices.