# ZwSetInformationResourceManager function

## Description

The **ZwSetInformationResourceManager** routine is not used.

## Parameters

### `ResourceManagerHandle`

### `ResourceManagerInformationClass`

### `ResourceManagerInformation`

### `ResourceManagerInformationLength`

## Return value

This function does not return a value.

## Remarks

**NtSetInformationResourceManager** and **ZwSetInformationResourceManager** are two versions of the same Windows Native System Services routine.

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)