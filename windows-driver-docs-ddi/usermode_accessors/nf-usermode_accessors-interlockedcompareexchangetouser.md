## Description

The **InterlockedCompareExchangeToUser** function performs an atomic compare-and-exchange operation on a 32-bit value in user-mode memory.

## Parameters

### `Destination`

[in, out] A pointer to the user-mode memory location containing the destination value. The pointer must be naturally aligned for the data type; that is, the memory location must be 4-byte aligned since **Destination** points to a 4-byte type.

### `ExChange`

[in] The exchange value.

### `Comperand`

[in] The value to compare to **Destination**.

## Return value

The function returns the initial value of the **Destination** parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions. It generates a full memory barrier to ensure that memory operations are completed in order.

This function provides atomic compare-and-exchange access to a 32-bit value in user-mode memory. The function compares the **Destination** value with the **Comperand** value. If the **Destination** value is equal to the **Comperand** value, the **ExChange** value is stored in the address specified by **Destination**. Otherwise, no operation is performed.

The function raises a structured exception if the operation fails, such as when the destination address is not a valid user-mode address or is inaccessible.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**InterlockedCompareExchangeToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedcompareexchangetomode)

[**InterlockedCompareExchange64ToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedcompareexchange64touser)