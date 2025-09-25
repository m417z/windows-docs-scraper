# ID_ERROR_OBJECT structure

## Description

The
**ID_ERROR_OBJECT** structure contains error message information for Identity Policy Elements for RSVP.

## Members

### `usIdErrLength`

Length of **udIdErrData**, in bytes.

### `ucAType`

Type of Identity Policy Element error.

### `ucSubType`

Sub-type of the Identity Policy Element error.

### `usReserved`

Reserved. Do not use.

### `usIdErrorValue`

Value for the Identity Policy Element error.

### `ucIdErrData`

Identity Policy Element error data.

## See also

[Policy Elements](https://learn.microsoft.com/previous-versions/windows/desktop/qos/policy-elements)