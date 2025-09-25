## Description

The **StringLengthFromUser** function safely calculates the length of a null-terminated string in user-mode memory.

## Parameters

### `String`

[in] A pointer to a null-terminated string in user-mode memory.

## Return value

The function returns the length of the string in characters, not including the terminating null character.

## Remarks

This function provides safe access to calculate the length of a null-terminated string located in user-mode memory. It is designed for use by kernel-mode code that needs to determine the length of strings passed from user-mode applications.

The function ensures that the string address is a valid user-mode address before performing the length calculation. It raises a structured exception if the operation fails, such as when the string address is not a valid user-mode address or is inaccessible.

Unlike standard string functions, this function includes validation to prevent kernel crashes when accessing potentially invalid user-mode pointers. This makes it essential for secure kernel programming when processing user-mode string data.

This function works on all versions of Windows, not just the latest. You need to consume the latest WDK to get the function declaration from the *usermode_accessors.h* header. You also need the library (*umaccess.lib*) from the latest WDK. However, the resulting driver will run fine on older versions of Windows.

## See also

[**StringLengthFromMode**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-stringlengthfrommode)

[**WideStringLengthFromUser**](https://learn.microsoft.com/windows-hardware/drivers/ddi/usermode_accessors/nf-usermode_accessors-widestringlengthfromuser)