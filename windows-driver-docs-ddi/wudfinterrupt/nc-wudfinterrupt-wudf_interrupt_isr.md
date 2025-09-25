# WUDF_INTERRUPT_ISR callback function

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

A driver's *OnInterruptIsr* event callback function services a hardware interrupt.

## Parameters

### `Interrupt` [in]

A pointer to the [IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt) interface.

### `MessageID` [in]

If the device is using message-signaled interrupts (MSIs), this parameter is the message number that identifies the device's hardware interrupt message. Otherwise, this value is 0.

### `Reserved` [in]

Reserved for system use.

## Syntax

```cpp
typedef
BOOLEAN
_Function_class_(WUDF_INTERRUPT_ISR)
WUDF_INTERRUPT_ISR(
    _In_
    IWDFInterrupt* Interrupt,
    _In_
    ULONG MessageID,
    _In_
    ULONG Reserved
    );

typedef WUDF_INTERRUPT_ISR *PFN_WUDF_INTERRUPT_ISR;
```

## Remarks

Returns TRUE if the driver acknowledges ownership of the interrupt, and has stopped and acknowledged the interrupt on its device. Otherwise, returns FALSE.

To register an *OnInterruptIsr* callback function, your driver must place the callback function's address in a [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure before calling [IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt).

The *OnInterruptIsr* callback function is a UMDF driver's interrupt service routine (ISR), which is called at PASSIVE_LEVEL when a hardware interrupt occurs.

For an edge-triggered interrupt or message-signaled interrupt (MSI), the framework calls *OnInterruptIsr* outside of the operating system's interrupt dispatch context. This is because UMDF allows only non-shared edge-triggered or MSI interrupts, and the driver does not need to interact with its hardware within this context.

For a level-triggered interrupt, the framework calls *OnInterruptIsr* in the context of the operating system's interrupt dispatch. As a result, the operating system's interrupt dispatch thread is blocked in kernel-mode waiting for a response from the driver.

Typically, *OnInterruptIsr* saves any volatile information that might be lost and clears the hardware interrupt. For a level-triggered interrupt, the driver should stop and acknowledge the interrupt on the device and then return TRUE if it owns the interrupt. The driver should do any further processing in an [OnInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_workitem) callback. To queue a work item, the driver calls the [IWDFInterrupt::QueueWorkItemForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-queueworkitemforisr) method.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

### Examples

The function type is declared in *Wudfinterrupt.h*, as follows.

```cpp
typedef
BOOLEAN
WUDF_INTERRUPT_ISR(
    _In_
    IWDFInterrupt* Interrupt,
    _In_
    ULONG MessageID,
    _In_
    ULONG Reserved
    );

typedef WUDF_INTERRUPT_ISR *PFN_WUDF_INTERRUPT_ISR;
```

To define an *OnInterruptIsr* callback function that is named *MyInterruptIsr*, you must first provide a function declaration that SDV and other verification tools require, as follows:

```cpp
WUDF_INTERRUPT_NOTIFY  MyInterruptIsr;
```

Then, implement your callback function as follows:

```cpp
BOOLEAN
  MyInterruptIsr (
    IN IWDFInterrupt*  Interrupt,
    IN ULONG  MessageID,
    IN ULONG Reserved
    )
  {…}

```

## See also

- [IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt)
- [OnInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_workitem)
- [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config)