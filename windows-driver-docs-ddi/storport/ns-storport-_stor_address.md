# _STOR_ADDRESS structure (storport.h)

## Description

 A general structure for holding a storage device address.

## Members

### `Type`

The address type. This can be one of the following:

| Value | Meaning |
| --- | --- |
| **STOR_ADDRESS_TYPE_UNKNOWN** | The address type is unknown. |
| **STOR_ADDRESS_TYPE_BTL8** | The address is an 8-bit Bus-Target-LUN address. |

### `Port`

The host bus adapter (HBA) port number.

### `AddressLength`

The byte length of the **AddressData**. If **Type** is set to **STOR_ADDRESS_TYPE_BTL8**, this value is **STOR_ADDR_BTL8_ADDRESS_LENGTH**.

### `AddressData`

The address data specific to an address type.

## See also

[STOR_ADDR_BTL8](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8)

[StorPortSetUnitAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetunitattributes)