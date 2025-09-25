# _STOR_ADDR_BTL8 structure (scsi.h)

## Description

 The **STOR_ADDR_BTL8** address structure contains the addressing information for an 8-bit Bus-Target-LUN (BTL8) address.

## Members

### `Type`

The address type. This member is set to **STOR_ADDRESS_TYPE_BTL8**.

### `Port`

The host bus adapter (HBA) port number.

### `AddressLength`

The byte length of the address. This value is set to **STOR_ADDR_BTL8_ADDRESS_LENGTH**.

### `Path`

The bus number for the target device.

### `Target`

The target device number.

### `Lun`

The logical unit on the target device.

### `Reserved`

Reserved, set to 0.

## See also

[STOR_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_address)