## Description

The **InterlockedOrToMode** function performs an atomic OR operation on a 32-bit value, based on the specified processor mode.

## Parameters

### `Destination`

[in, out] A pointer to the memory location containing the first operand. This value will be replaced with the result of the operation. The pointer must be naturally aligned for the data type; that is, the memory location must be 4-byte aligned since **Destination** points to a 4-byte type.

### `Value`

[in] The second operand.

### `Mode`

[in] The processor mode that determines how the memory access is performed. **Mode** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **KernelMode** | **Destination** points to kernel-mode memory. The function performs a direct atomic OR operation. See Remarks for more details. |
| **UserMode** | **Destination** points to user-mode memory. The function raises an exception if **Destination** doesn't point to user-mode memory; otherwise it performs an atomic OR operation at the specified address. See Remarks for more details. |

## Return value

The function returns the original value of the **Destination** parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions. It generates a full memory barrier to ensure that memory operations are completed in order.

This function provides atomic access to a 32-bit value in memory, performing a bitwise OR operation between the value at **Destination** and **Value**. The behavior depends on the processor mode specified:

- When **Mode** is **UserMode**, the function ensures that the destination address is a valid user-mode address and performs the operation safely for user-mode memory access.
- When **Mode** is **KernelMode**, the function operates directly on kernel-mode addresses.

The function raises a structured exception if the operation fails, such as when the destination address is not accessible or is invalid for the specified mode.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**InterlockedOrToUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedortouser)

[**InterlockedOr64ToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedor64tomode)

[**InterlockedAndToMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-interlockedandtomode)