# IWDFObject::AcquireLock

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AcquireLock** method prevents the framework from calling methods of interfaces that a driver registered.

## Remarks

If a driver configured itself to use the **AcquireLock** locking scheme, the framework automatically acquires the "presentation" lock before calling into the driver. (For more information about this locking scheme, see [Specifying a Callback Synchronization Mode](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-a-callback-synchronization-mode).) The **AcquireLock** and [IWDFObject::ReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-releaselock) methods acquire and release the presentation lock, respectively. [Framework device objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/creating-a-framework-device-object) and [framework I/O queue objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-i-o-queue-object) currently support the **AcquireLock** method.

The driver calls the **AcquireLock** method to manipulate its objects that were created from its callback interfaces outside the callback scope in a thread-safe manner. The **AcquireLock** method represents an advanced feature of the framework that most drivers will not use because improper usage can result in deadlocks.

Unsynchronized code can call **AcquireLock**. The driver should call on objects that match its synchronization scope.

#### Examples

For a code example of how to use the **AcquireLock** method, see [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate).

## See also

[IWDFObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfobject)

[IWDFObject::ReleaseLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-releaselock)