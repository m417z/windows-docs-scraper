# MsiEnumRelatedProductsW function

## Description

The
**MsiEnumRelatedProducts** function enumerates products with a specified upgrade code. This function lists the currently installed and advertised products that have the specified
[UpgradeCode](https://learn.microsoft.com/windows/desktop/Msi/upgradecode) property in their
[Property table](https://learn.microsoft.com/windows/desktop/Msi/property-table).

## Parameters

### `lpUpgradeCode` [in]

The null-terminated string specifying the upgrade code of related products that the installer is to enumerate.

### `dwReserved` [in]

This parameter is reserved and must be 0.

### `iProductIndex` [in]

The zero-based index into the registered products.

### `lpProductBuf` [out]

A buffer to receive the product code GUID. This buffer must be 39 characters long. The first 38 characters are for the
[GUID](https://learn.microsoft.com/windows/desktop/Msi/guid), and the last character is for the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no products to return. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system does not have enough memory to complete the operation. Available starting with Windows Server 2003. |
| **ERROR_SUCCESS** | A value was enumerated. |

## Remarks

See
[UpgradeCode](https://learn.microsoft.com/windows/desktop/Msi/upgradecode) property.

To enumerate currently installed and advertised products that have a specific upgrade code, an application should initially call the
**MsiEnumRelatedProducts** function with the *iProductIndex* parameter set to zero. The application should then increment the *iProductIndex* parameter and call
**MsiEnumRelatedProducts** until the function returns ERROR_NO_MORE_ITEMS, which means there are no more products with the specified upgrade code.

When making multiple calls to
**MsiEnumRelatedProducts** to enumerate all of the related products, each call should be made from the same thread.

> [!NOTE]
> The msi.h header defines MsiEnumRelatedProducts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).