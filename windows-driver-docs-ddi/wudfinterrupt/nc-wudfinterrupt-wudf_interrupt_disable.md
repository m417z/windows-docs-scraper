# WUDF_INTERRUPT_DISABLE callback function

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

A driver's *OnInterruptDisable* event callback function disables a specified hardware interrupt.

## Parameters

### `Interrupt` [in]

A pointer to the [IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt) interface.

### `AssociatedDevice` [in]

A pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface that the driver used to call [CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt).

## Return value

*OnInterruptDisable* must return S_OK if the operation succeeds. Otherwise, the callback should return one of the error codes that are defined in Winerror.h.

## Remarks

To register an *OnInterruptDisable* callback function, your driver must place the callback function's address in a [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure before calling [IWDFDevice::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt).

The framework calls the driver's *OnInterruptDisable* callback function each time the device leaves its working (D0) state. Additionally, a driver can cause the framework to call the *OnInterruptDisable* callback function by calling [IWDFInterrupt::Disable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-disable).

Before calling the *OnInterruptDisable* callback function, the framework calls the driver's [OnD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardwareinterrupt-ond0exitpreinterruptsdisabled) event callback function and acquires the user-mode interrupt lock.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

### Examples

The function type is declared in *Wudfinterrupt.h*, as follows.

```cpp
typedef
__drv_functionClass(WUDF_INTERRUPT_DISABLE)
HRESULT
WUDF_INTERRUPT_DISABLE(
    _In_
    IWDFInterrupt* Interrupt,
    _In_
    IWDFDevice* AssociatedDevice
    );

typedef WUDF_INTERRUPT_DISABLE *PFN_WUDF_INTERRUPT_DISABLE;
```

To define an *OnInterruptDisable* callback function that is named *MyInterruptDisable*, you must first provide a function declaration that SDV and other verification tools require, as follows:

```cpp
WUDF_INTERRUPT_DISABLE  MyInterruptDisable;
```

Then, implement your callback function as follows:

```cpp
HRESULT
  MyInterruptDisable (
    IN IWDFInterrupt* pInterrupt,
    IN IWDFDevice*  pAssociatedDevice
    )
  {…}

```

## See also

- [IWDFDevice::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt)
- [OnInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_enable)
- [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config)