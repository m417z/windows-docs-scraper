# WUDF_INTERRUPT_WORKITEM callback function

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

 A driver's *OnInterruptWorkItem* event callback function processes interrupt information that the driver's [OnInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_isr) callback function has stored.

## Parameters

### `Interrupt` [in]

A pointer to the interrupt object interface associated with the work item.

### `AssociatedObject` [in]

A pointer to the associated object.

## Remarks

To register an *OnInterruptWorkItem* callback function, your driver must place the callback function's address in a [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure before calling [IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt).

After stopping and acknowledging the interrupt, the driver should return quickly from its [OnInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_isr) callback, postponing any additional processing to a *OnInterruptWorkItem* callback.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

#### Examples

The function type is declared in *Wudfworkitem.h*, as follows.

```
typedef
_Function_class_(WUDF_INTERRUPT_WORKITEM)
VOID
WUDF_INTERRUPT_WORKITEM(
    _In_
    IWDFInterrupt* Interrupt,
    _In_
    IWDFObject* AssociatedObject
    );

typedef WUDF_INTERRUPT_WORKITEM *PFN_WUDF_INTERRUPT_WORKITEM;
```

To define an *OnInterruptWorkItem* callback function that is named *MyInterruptWorkItem*, you must first provide a function declaration that SDV and other verification tools require, as follows:

```
WUDF_INTERRUPT_WORKITEM  MyInterruptWorkItem;
```

Then, implement your callback function as follows:

```
VOID
  MyInterruptWorkItem (
    _In_
    IWDFInterrupt* Interrupt,
    _In_
    IWDFObject* AssociatedObject
    )
  {…}

```

## See also

[IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt)

[WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config)