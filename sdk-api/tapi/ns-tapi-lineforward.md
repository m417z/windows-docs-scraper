# LINEFORWARD structure

## Description

The
**LINEFORWARD** structure describes an entry of the forwarding instructions. The
[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist) and the
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus) structures can contain an array of
**LINEFORWARD** structures.

## Members

### `dwForwardMode`

Types of forwarding. This member uses one of the
[LINEFORWARDMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineforwardmode--constants).

### `dwCallerAddressSize`

Size of the variably sized field containing the address of a caller to be forwarded, in bytes.

### `dwCallerAddressOffset`

Offset from the beginning of this structure to the variably sized field containing the address of a caller to be forwarded. This member is set to zero if **dwForwardMode** is not one of the following values:

#### LINEFORWARDMODE_BUSYNASPECIFIC

#### LINEFORWARDMODE_NOANSWSPECIFIC

#### LINEFORWARDMODE_UNCONDSPECIFIC

#### LINEFORWARDMODE_BUSYSPECIFIC

The size of the field is specified by **dwCallerAddressSize**.

### `dwDestCountryCode`

Country or region code of the destination address to which the call is to be forwarded.

### `dwDestAddressSize`

Size of the variably sized field containing the address of the address where calls are to be forwarded, in bytes.

### `dwDestAddressOffset`

Offset from the beginning of this structure to the variably sized field containing the address of the address where calls are to be forwarded. The size of the field is specified by **dwDestAddressSize**.

### `dwCallerAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) of the caller. This member of the structure is available only if the negotiated version of TAPI is 3.1 or higher.

### `dwDestAddressType`

[Address type](https://learn.microsoft.com/windows/desktop/Tapi/lineaddresstype--constants) for the called destination. This member of the structure is available only if the negotiated version of TAPI is 3.1 or higher.

## Remarks

This structure may not be extended.

Each entry in the
**LINEFORWARD** structure specifies a forwarding request.

## See also

[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus)

[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist)

[TSPI_lineForward](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineforward)

[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward)