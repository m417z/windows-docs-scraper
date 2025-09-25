## Description

The **ZwFlushKey** routine forces a registry key to be committed to disk.

## Parameters

### `KeyHandle` [in]

Handle to the registry key to be flushed to disk. This handle is created by a successful call to [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey).

## Return value

**ZwFlushKey** returns STATUS_SUCCESS if the key information was transferred to disk, or the appropriate error code on failure.

## Remarks

You can flush changes made by [ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey) or [ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey) by calling **ZwFlushKey**. This routine does not return until all the changed data that is associated with *KeyHandle* has been written to disk. **ZwFlushKey** flushes the entire registry hive for the key, which includes every subkey of the key specified.

This routine can flush the entire registry. Accordingly, it can generate a great deal of I/O. Since the system flushes key changes automatically every few seconds, you seldom need to call **ZwFlushKey**.

For more information about working with registry keys, see [Using the Registry in a Driver](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-the-registry-in-a-driver).

If the call to this function occurs in user mode, you should use the name "**NtFlushKey**" instead of "**ZwFlushKey**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwCreateKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwcreatekey)

[ZwOpenKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwopenkey)

[ZwSetValueKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwsetvaluekey)