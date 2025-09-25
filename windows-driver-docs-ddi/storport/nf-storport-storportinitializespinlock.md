# StorPortInitializeSpinlock function

## Description

The **StorPortInitializeSpinLock** routine initializes a variable of type **STOR_KSPIN_LOCK**.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `Lock` [out]

Pointer to a spin lock of type **STOR_KSPIN_LOCK**, for which the caller must provide the storage

## Return value

**StorPortInitializeSpinlock** returns a status code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STOR_STATUS_NOT_IMPLEMENTED | This function is not implemented on the active operating system. |
| STOR_STATUS_SUCCESS | The list items were removed successfully or the list is already empty. |

## Remarks

This routine must be called before an initial call to [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock), to any other support routine that requires a spin lock as an argument.

For more information about spin locks, see [Spin Locks](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks).

## See also

[**StorPortAcquireMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquiremsispinlock)

[**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock)

[**StorPortReleaseMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasemsispinlock)

[**StorPortReleaseSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasespinlock)