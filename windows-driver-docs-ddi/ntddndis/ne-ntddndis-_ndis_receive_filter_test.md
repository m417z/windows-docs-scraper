# _NDIS_RECEIVE_FILTER_TEST enumeration

## Description

The **NDIS_RECEIVE_FILTER_TEST** enumeration identifies the type of test that the receive filter
performs.

## Constants

### `NdisReceiveFilterTestUndefined`

The type of test is not specified.

### `NdisReceiveFilterTestEqual`

The network adapter tests the selected header field to determine whether it is equal to a specific
value.

### `NdisReceiveFilterTestMaskEqual`

The network adapter supports masking (that is, a bitwise AND) of the selected header field to
determine whether the result is equal to a specific value.

### `NdisReceiveFilterTestNotEqual`

The network adapter tests the selected header field to determine whether it is not equal to a specific
value.

### `NdisReceiveFilterTestMaximum`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The NDIS_RECEIVE_FILTER_TEST enumeration is used in the
[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters) structure.

## See also

[NDIS_RECEIVE_FILTER_FIELD_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_receive_filter_field_parameters)