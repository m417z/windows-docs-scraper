# GPIO_CLX_AcquireInterruptLock function

## Description

The **GPIO_CLX_AcquireInterruptLock** method acquires an interrupt lock on a bank of pins in the general-purpose I/O (GPIO) controller.

## Parameters

### `Context` [in]

A pointer to the GPIO controller driver's [device context](https://learn.microsoft.com/windows-hardware/drivers/gpio/gpio-device-contexts). The GPIO framework extension (GpioClx) passes this pointer value as a parameter to the callback functions that are implemented by the GPIO controller driver.

### `BankId` [in]

The identifier for this bank of GPIO pins. If N is the number of banks in the GPIO controller, **BankId** is an integer in the range 0 to N–1.

## Remarks

A GPIO controller driver thread calls this method to synchronize to the interrupt service routine (ISR) in GpioClx. While the caller holds the interrupt lock, the ISR cannot call driver-implemented callback functions to access GPIO registers in the specified bank. A GPIO controller driver should call this method before it tries to access GPIO registers that might be accessed by the GpioClx ISR.

The GpioClx ISR calls driver-implemented callback functions to access interrupt status and enable registers in the GPIO controller. Depending on the capabilities of the GPIO controller, the ISR is called either at DIRQL or at PASSIVE_LEVEL. For more information, see [Interrupt-Related Callbacks](https://learn.microsoft.com/windows-hardware/drivers/gpio/interrupt-related-callbacks).

If the GpioClx ISR accesses these interrupt registers at DIRQL, **GPIO_CLX_AcquireInterruptLock** raises the calling thread's IRQL to the DIRQL at which the ISR runs. If the ISR runs at PASSIVE_LEVEL, this method does not change the calling thread's IRQL.

The [GPIO_CLX_ReleaseInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_releaseinterruptlock) method releases an interrupt lock that was acquired in a previous call to **GPIO_CLX_AcquireInterruptLock**. The **BankId** parameter specifies the bank that is affected by the lock. To release a lock on a bank, the **BankId** parameter of the **GPIO_CLX_ReleaseInterruptLock** call must match the **BankId** parameter of the **GPIO_CLX_AcquireInterruptLock** call that acquired the lock. If the **GPIO_CLX_AcquireInterruptLock** call raised the calling thread's IRQL, **GPIO_CLX_ReleaseInterruptLock** restores this thread's original IRQL.

The GPIO controller driver can independently acquire and release interrupt locks on the various banks in the GPIO controller. However, it is a fatal error for the driver to try to acquire a lock on a particular bank if the driver already holds a lock on this bank.

If the *Context* parameter is NULL or points to an invalid GPIO device context, this method causes a bug check in debug builds of GpioClx.

## See also

[GPIO_CLX_ReleaseInterruptLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/gpioclx/nf-gpioclx-gpio_clx_releaseinterruptlock)