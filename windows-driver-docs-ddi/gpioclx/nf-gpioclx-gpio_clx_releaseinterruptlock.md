# GPIO_CLX_ReleaseInterruptLock function

## Description

The **GPIO_CLX_ReleaseInterruptLock** method releases an interrupt lock on the specified bank.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts). The GPIO framework extension (GpioClx) passes this pointer value as a parameter to the callback functions that are implemented by the GPIO controller driver.

### `BankId` [in]

The identifier for this bank of GPIO pins. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1.

## Remarks

This method releases the interrupt lock that the caller acquired in a previous call to the [GPIO_CLX_AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_acquireinterruptlock) method.

If the previous call to the **GPIO_CLX_AcquireInterruptLock** method raised the calling thread's IRQL, **GPIO_CLX_ReleaseInterruptLock** restores this IRQL to its original level.

If the *Context* parameter is NULL or points to an invalid GPIO device context, this method causes a bug check in debug builds of GpioClx.

## See also

[GPIO_CLX_AcquireInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_acquireinterruptlock)