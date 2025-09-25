## Description

The **InterlockedAndToUser** function performs an atomic AND operation on a 32-bit value in user-mode memory.

## Parameters

### `Destination`

[in, out] A pointer to the user-mode memory location containing the first operand. This value will be replaced with the result of the operation. The pointer must be naturally aligned for the data type; that is, the memory location must be 4-byte aligned since **Destination** points to a 4-byte type.

### `Value`

[in] The second operand.

## Return value

The function returns the original value of the **Destination** parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions. It generates a full memory barrier to ensure that memory operations are completed in order.

This function provides atomic access to a 32-bit value in user-mode memory, performing a bitwise AND operation between the value at **Destination** and **Value**.

The function raises a structured exception if the operation fails, such as when the destination address is not a valid user-mode address or is inaccessible.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**InterlockedAndToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedandtomode)

[**InterlockedAnd64ToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedand64touser)

[**InterlockedOrToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedortouser)