# IWDFDevice3::CreateInterrupt

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateInterrupt** method creates a framework interrupt object.

## Parameters

### `Configuration` [in]

A pointer to a [WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config) structure that was initialized by a call to the [WUDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wudf_interrupt_config_init) macro.

### `ppInterrupt` [out]

A pointer to a buffer that receives a pointer to the [IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt) interface for the new interrupt object.

## Return value

The method returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Your driver must call **CreateInterrupt** one time for each interrupt vector that its device requires. If the device supports message-signaled interrupts (MSI), the driver must create an interrupt object for each message that the device can support.

Drivers typically call the **CreateInterrupt** method from an [OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) callback function, but can also call this method from [IPnpCallbackHardware2::OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware).

After the Plug and Play (PnP) manager assigns system resources to the device, the framework stores information about the device's assigned interrupt resources in the interrupt objects that the driver has created. (Drivers that do not support Plug and Play cannot use interrupt objects.)

The system might not assign all the interrupt resources that a device can support. For example, a driver creates eight interrupt objects for a device that is capable of supporting eight MSI messages. However, the system might assign only one message to the device. In that case, seven of the interrupt objects will be unused.

Typically, your driver should store interrupt-specific information, such as the copied contents of device interrupt registers, in the interrupt object's context space. A driver calls [IWDFObject::AssignContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-assigncontext) to register a context and to request notification when the object becomes invalid.

UMDF supports level-triggered interrupts starting in Windows 8. If a driver running on an operating system earlier than Windows 8 creates a level-triggered interrupt in [OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd), **CreateInterrupt** succeeds because the operating system has not yet assigned resources. However, when the framework attempts to connect the interrupt later, the device fails to start.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

#### Examples

```
HRESULT  hr;
IWDFInterrupt* pInterrupt;
WUDF_INTERRUPT_CONFIG  interruptConfig;

WUDF_INTERRUPT_CONFIG_INIT(&interruptConfig,
                           MyInterruptIsr,
                           MyInterruptWorkItem);

hr = pDevice->Create(&interruptConfig,
                     &pInterrupt);

```

## See also

[IWDFDevice3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice3)

[WUDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wudf_interrupt_config)

[WUDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wudf_interrupt_config_init)