# MsiEnumProductsA function

## Description

The
**MsiEnumProducts** function enumerates through all the products currently advertised or installed. Products that are installed in both the per-user and per-machine [installation context](https://learn.microsoft.com/windows/desktop/Msi/installation-context) and advertisements are enumerated.

## Parameters

### `iProductIndex` [in]

Specifies the index of the product to retrieve. This parameter should be zero for the first call to the
**MsiEnumProducts** function and then incremented for subsequent calls. Because products are not ordered, any new product has an arbitrary index. This means that the function can return products in any order.

### `lpProductBuf` [out]

Pointer to a buffer that receives the product code. This buffer must be 39 characters long. The first 38 characters are for the GUID, and the last character is for the terminating null character.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_NO_MORE_ITEMS** | There are no products to return. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system does not have enough memory to complete the operation. Available with Windows Server 2003. |
| **ERROR_SUCCESS** | A value was enumerated. |

## Remarks

To enumerate products, an application should initially call the
**MsiEnumProducts** function with the *iProductIndex* parameter set to zero. The application should then increment the *iProductIndex* parameter and call
**MsiEnumProducts** until there are no more products (until the function returns ERROR_NO_MORE_ITEMS).

When making multiple calls to
**MsiEnumProducts** to enumerate all of the products, each call should be made from the same thread.

> [!NOTE]
> The msi.h header defines MsiEnumProducts as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Determining Installation Context](https://learn.microsoft.com/windows/desktop/Msi/determining-installation-context)

[System Status Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)