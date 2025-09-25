# PropVariantGetInformation function

## Description

This routine gets offset, size, location pointer and DEVPROPTYPE, of a PROPVARIANT.

## Parameters

### `PropVariantValue` [in]

Pointer to a PROPVARIANT.

### `PropVariantOffset` [out]

The offset of the location pointer in PROPVARIANT.

### `PropVariantSize` [out]

Size of data.

### `PropVariantPointer` [out]

C
The location of data.

### `RemappedType` [out]

The DEVPROPTYPE.

## Return value

This function returns STATUS_NOT_SUPPORTED if the PROPVARIANT is not a supported type, STATUS_SUCCESS otherwise.

## Remarks

## See also