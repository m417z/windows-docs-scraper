# VideoPortSynchronizeExecution function

## Description

The **VideoPortSynchronizeExecution** function synchronizes the execution of a miniport driver-supplied [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function with the miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) function, if any. Otherwise, it runs *HwVidSynchronizeExecutionCallback* at a raised priority.

## Parameters

### `HwDeviceExtension`

Pointer to the miniport driver's device extension.

### `Priority`

Specifies the type of priority at which the given *SynchronizeRoutine* must be run, as one of the following:

* If *Priority* is set to **VpLowPriority**, the current thread is raised to the highest noninterrupt-masking priority. Accordingly, the current thread can be preempted only by an ISR if a device interrupts.
* If *Priority* is set to **VpMediumPriority** and the miniport driver has an ISR associated with its video adapter, the call to the given *SynchronizeRoutine* is synchronized with the miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) function. Otherwise, synchronization is made at the **VpLowPriority** level.
* **VpHighPriority** has the same effect as **VpMediumPriority**.

### `SynchronizeRoutine`

Pointer to the miniport driver's [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) function.

### `Context`

Pointer to a caller-supplied context to be passed to the miniport driver's *HwVidSynchronizeExecutionCallback* function. This pointer can be **NULL**.

## Return value

If the operation succeeds, **VideoPortSynchronizeExecution** returns **TRUE**.

## Remarks

Miniport drivers seldom call this routine unless either of the following conditions hold:

* The miniport driver's [HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt) function shares memory with other miniport driver functions. In order to access the shared memory in a multiprocessor-safe way, such miniport driver functions must call **VideoPortSynchronizeExecution** with [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine). This miniport driver function can safely access the shared memory because the video port driver prevents the *HwVidInterrupt* function from accessing the same memory concurrently.
* The adapter must be programmed with a sequence of commands without being subject to a context switch. For example, a miniport driver's *SvgaHwIoPortXxx* function that has buffered a sequence of I/O instructions and validated the sequence might call **VideoPortSynchronizeExecution** with *HwVidSynchronizeExecutionCallback*. This miniport driver function can transfer the buffered and validated I/O stream to the adapter very quickly.

A caller should specify the lowest practical *Priority* value for the work [HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine) must do. Any *CallbackRoutine* that is run at a high hardware priority (**VpMediumPriority** or **VpHighPriority**) should return control as quickly as possible. A driver with such a high-priority *HwVidSynchronizeExecutionCallback* function should be designed to do as much work as possible in every other driver function except one of both of its *HwVidSynchronizeExecutionCallback* and *HwVidInterrupt* functions.

Callers of **VideoPortSynchronizeExecution** must be running at IRQL

## See also

[HwVidInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pvideo_hw_interrupt)

[HwVidSynchronizeExecutionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nc-video-pminiport_synchronize_routine)