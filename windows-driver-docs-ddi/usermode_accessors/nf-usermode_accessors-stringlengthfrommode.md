## Description

The **StringLengthFromMode** function calculates the length of a null-terminated string, based on the specified processor mode.

## Parameters

### `String`

[in] A pointer to a null-terminated string.

### `Mode`

[in] The processor mode that determines how the memory access is performed. **Mode** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| **KernelMode** | **String** points to kernel-mode memory. The function performs a direct string length calculation. See Remarks for more details. |
| **UserMode** | **String** points to user-mode memory. The function raises an exception if **String** doesn't point to user-mode memory; otherwise it performs a safe string length calculation at the specified address. See Remarks for more details. |

## Return value

The function returns the length of the string in characters, not including the terminating null character.

## Remarks

This function provides safe access to calculate the length of a null-terminated string in memory. The behavior depends on the processor mode specified:

- When **Mode** is **UserMode**, the function ensures that the string address is a valid user-mode address and performs the operation safely for user-mode memory access.
- When **Mode** is **KernelMode**, the function operates directly on kernel-mode addresses.

When the mode is **UserMode**, the function includes validation to prevent kernel crashes when accessing potentially invalid user-mode pointers. When the mode is **KernelMode**, it operates on known-safe kernel addresses for optimal performance.

The function raises a structured exception if the operation fails, such as when the string address is not accessible or is invalid for the specified mode.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**StringLengthFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-stringlengthfromuser)

[**WideStringLengthFromMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-widestringlengthfrommode)