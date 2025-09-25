# _GET_UNIT_IDS structure

## Description

The GET_UNIT_CAPABILITIES structure is used in conjunction with the [Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85)) request to retrieve device identifiers.

## Members

### `UniqueID`

The unique ID for the device from the bus information block within the configuration ROM of the unit.

### `VendorID`

The vendor ID for the device.

### `ModelID`

The model ID for the device. This value is retrieved from the root directory within the device's Configuration ROM.

### `ulVendorLength`

The length, in bytes, of the vendor text string, including the terminating UNICODE_NULL. If **ulVendorLength** is not zero in the input GET_UNIT_IDS structure, **VendorText** must point to a buffer whose size is **sizeof(ulVendorLength)**.

### `VendorText`

Points to a buffer that receives the "friendly name" for the vendor as a Unicode string terminated with a UNICODE_NULL. If **ulVendorLength** is zero in the input GET_UNIT_IDS structure, **VendorText** is **NULL**.

### `ulModelLength`

The length, in bytes, of the model text string, including the terminating UNICODE_NULL. If **ulModelLength** is not zero in the input GET_UNIT_IDS structure, **ModelText** must point to a buffer whose size is **sizeof(ulModelLength)**.

### `ModelText`

Points to a buffer to receive the "friendly name" for the model as a Unicode string terminated with a UNICODE_NULL. If **ulModelLength** is zero in the input GET_UNIT_IDS structure, **ModelText** is **NULL**. This value is retrieved from the root directory within the device's Configuration ROM.

### `UnitModelID`

The model ID for the device. This value is retrieved from the unit directory within the device's Configuration ROM.

### `ulUnitModelLength`

The length, in bytes, of the model text string, including the terminating UNICODE_NULL. If **ulUnitModelLength** is not zero in the input GET_UNIT_IDS structure, **UnitModelText** must point to a buffer whose size is **sizeof(ulUnitModelLength)**.

### `UnitModelText`

Points to a buffer that receives the "friendly name" for the model represented as a Unicode string terminated with a UNICODE_NULL. If **ulUnitModelLength** is zero in the input GET_UNIT_IDS structure, **UnitModelText** will be **NULL**. This value is retrieved from the unit directory within the device's Configuration ROM.

## See also

[Av61883_GetUnitInfo](https://learn.microsoft.com/previous-versions/ff536983(v=vs.85))