## Description

The class driver calls the minidriver's *StrMiniCancelPacket* routine to signal that a stream request has been canceled.

## Parameters

### `SRB` [in]

Pointer to the stream request that had been canceled.

## Remarks

The minidriver specifies this routine in the **HwCancelPacket** member of its [HW_INITIALIZATION_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure. The minidriver passes this structure to the class driver when it registers itself by calling [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter).

Minidrivers that rely on the class driver to handle synchronization should, once they have successfully canceled a request, signal to the class driver that they are ready for another request by using [StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification) or [StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification) with the appropriate **ReadyForNext***Xxx***Request**.