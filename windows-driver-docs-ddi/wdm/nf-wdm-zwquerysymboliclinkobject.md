## Description

The **ZwQuerySymbolicLinkObject** routine returns a Unicode string that contains the target of a symbolic link.

## Parameters

### `LinkHandle` [in]

Handle to the symbolic-link object that you want to query. This handle is created by a successful call to [ZwOpenSymbolicLinkObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopensymboliclinkobject).

### `LinkTarget` [in, out]

Pointer to an initialized Unicode string that receives the target of the symbolic link.

### `ReturnedLength` [out, optional]

 contains the maximum number of bytes to copy into the Unicode string at *LinkTarget*. On output, the unsigned long integer contains the length of the Unicode string naming the target of the symbolic link.

## Return value

**ZwQuerySymbolicLinkObject** returns either STATUS_SUCCESS to indicate the routine completed without error or STATUS_BUFFER_TOO_SMALL if the Unicode string provided at *LinkTarget* is too small to hold the returned string.

## Remarks

Before calling this routine, driver writers must ensure that the Unicode string at *LinkTarget* has been properly initialized and a buffer for the string has been allocated. The **MaximumLength** and **Buffer** members of the Unicode string must be set before calling **ZwQuerySymbolicLinkObject** or the call will fail.

If **ZwQuerySymbolicLinkObject** returns STATUS_BUFFER_TOO_SMALL drivers should examine the value returned at *ReturnedLength*. The number returned in this variable indicates the maximum length that the Unicode string for the target of the symbolic link.

If the call to this function occurs in user mode, you should use the name "**NtQuerySymbolicLinkObject**" instead of "**ZwQuerySymbolicLinkObject**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwOpenSymbolicLinkObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopensymboliclinkobject)