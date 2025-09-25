# CmGetBoundTransaction function

## Description

The **CmGetBoundTransaction** routine returns a pointer to the transaction object that represents the [transaction](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-kernel-transaction-manager), if any, that is associated with a specified registry key object.

## Parameters

### `Cookie` [in]

The cookie value that the driver previously obtain by calling [CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback) or [CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex).

### `Object` [in]

The pointer value that the driver's [RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function) callback routine received in one of the **REG_*XXX*_KEY_INFORMATION** structures.

## Return value

**CmGetBoundTransaction** returns a pointer to a transaction object, if the key object that the *Object* parameter specifies is associated with a transaction. Otherwise, the routine returns **NULL**.

## Remarks

The **CmGetBoundTransaction** routine is available on Windows Vista and later versions of Windows.

For more information about **CmGetBoundTransaction** and filtering registry operations, see [Filtering Registry Calls](https://learn.microsoft.com/windows-hardware/drivers/kernel/filtering-registry-calls).

For more information about transactions, see [Kernel Transaction Manager Design Guide](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-kernel-transaction-manager).

## See also

[CmRegisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallback)

[CmRegisterCallbackEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-cmregistercallbackex)

[RegistryCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ex_callback_function)