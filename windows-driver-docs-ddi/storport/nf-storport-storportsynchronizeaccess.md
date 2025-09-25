# StorPortSynchronizeAccess function

## Description

The **StorPortSynchronizeAccess** routine provides synchronized access to a miniport driver's device extension.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `SynchronizedAccessRoutine` [in]

Pointer to a caller-supplied routine whose execution is to be synchronized with the execution of the ISR associated with the interrupt objects. For a prototype of this routine, see the Remarks section later in this topic.

### `Context` [in, optional]

Pointer to a context area to be passed to the caller-supplied callback routine when it is called.

## Return value

The return value from *SynchronizedAccessRoutine*.

## Remarks

Miniport drivers that operate in full-duplex mode, and that access information that is shared between their [HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine and interrupt-service routine, must use this routine to access the shared data in a synchronized manner.

The miniport driver passes a callback routine to **StorPortSynchronizeAccess**, and **StorPortSynchronizeAccess** calls it after guaranteeing exclusive access to sensitive data structures. The miniport driver's callback routine must conform to the following prototype:

```
typedef
BOOLEAN
(* PSTOR_SYNCHRONIZED_ACCESS) (
  IN PVOID HwDeviceExtension,
 IN PVOID Context
  );
```

where *HwDeviceExtension* is a pointer to the hardware device extension, and *Context* is just a pointer to the same context information that the caller supplied when calling **StorPortSynchronizeAccess**.

For more information, see [Synchronized Access within Unsynchronized Miniport Driver Routines](https://learn.microsoft.com/windows-hardware/drivers/storage/synchronized-access-within-unsynchronized-miniport-driver-routines).

For more information about synchronization routines, see [KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution).

## See also

[KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution)