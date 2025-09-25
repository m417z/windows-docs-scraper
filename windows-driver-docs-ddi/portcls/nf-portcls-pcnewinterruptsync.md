# PcNewInterruptSync function

## Description

The **PcNewInterruptSync** function creates and initializes an interrupt-synchronization object.

## Parameters

### `OutInterruptSync` [out]

Output pointer for the interrupt-synchronization object created by this function. This parameter points to a caller-allocated pointer variable into which the function outputs a reference to the newly created [IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync) object. Specify a valid, non-**NULL** pointer value for this parameter.

### `OuterUnknown` [in, optional]

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of an object that needs to aggregate the object. Unless aggregation is required, set this parameter to **NULL**.

### `ResourceList` [in]

Pointer to the [IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist) object that was provided to the miniport driver during initialization. The port driver will examine this resource list but will not modify it.

### `ResourceIndex` [in]

Specifies the index of the interrupt resource in the resource list. If the [IResourceList::NumberOfEntriesOfType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-numberofentriesoftype) method returns a count of N for type CmResourceTypeInterrupt, *ResourceIndex* must be a value in the range 0 to N-1.

### `Mode` [in]

Specifies the way that multiple ISRs are handled. Set this parameter to one of the INTERRUPTSYNCMODE enumeration values. For more information, see the following Remarks section.

## Return value

**PcNewInterruptSync** returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

The *Mode* parameter is set to one of the INTERRUPTSYNCMODE enumeration values in the following table.

| Value | Meaning |
| --- | --- |
| **InterruptSyncModeNormal** | Call each ISR in the list until one of them returns STATUS_SUCCESS. |
| **InterruptSyncModeAll** | Call each ISR in the list exactly once, regardless of the return codes of the various ISRs. |
| **InterruptSyncModeRepeat** | Traverse the entire ISR list until a trip through the list occurs in which no ISR in the list returns STATUS_SUCCESS. |

For detailed descriptions of these three modes, see [Interrupt Sync Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/interrupt-sync-objects).

The *OutInterruptSync*, *OuterUnknown*, and *ResourceList* parameters follow the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IInterruptSync](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iinterruptsync)

[IResourceList](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iresourcelist)

[IResourceList::NumberOfEntriesOfType](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iresourcelist-numberofentriesoftype)