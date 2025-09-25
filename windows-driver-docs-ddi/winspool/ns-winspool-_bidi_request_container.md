# _BIDI_REQUEST_CONTAINER structure

## Description

The BIDI_REQUEST_CONTAINER structure is a container for a list of bidi requests.

## Members

### `Version`

Specifies the version of the bidi API Schema, which is currently 1.

### `Flags`

Is a set of flags reserved for system use. This must be zero.

### `Count`

Specifies the number of bidi requests in the **aData** member. A container can contain zero or more requests, although a value of zero is valid only if the action is BIDI_ACTION_ENUM_SCHEMA.

### `aData`

Is an array of [BIDI_REQUEST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_request_data) structures, each holding a single bidi request.

## Remarks

Even though the **aData** member of this structure is an array with only a single array element, **aData**[0] should be thought of as the first element of an array of (possibly) an arbitrarily large size.

## See also

[BIDI_REQUEST_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/winspool/ns-winspool-_bidi_request_data)