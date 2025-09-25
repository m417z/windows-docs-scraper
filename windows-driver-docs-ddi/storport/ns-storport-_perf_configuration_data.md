# _PERF_CONFIGURATION_DATA structure

## Description

The PERF_CONFIGURATION_DATA structure describes the performance optimizations that are supported by the [StorPortInitializePerfOpts](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeperfopts) routine.

## Members

### `Version`

The version number of the structure. Set this member when querying and initializing optimizations.

### `Size`

The size of the structure, set to **sizeof(PERF_CONFIGURATION_DATA)**.

### `Flags`

A bitwise-OR of supported flags. Currently, the following flags are supported:

| Flag | Meaning |
| --- | --- |
| STOR_PERF_DPC_REDIRECTION | This flag is used to indicate that DPC processing should be spread out over multiple CPUs.<br><br>This flag is valid when **Version** is set to 2 or 3. |
| STOR_PERF_CONCURRENT_CHANNELS | This flag is used to indicate that concurrent calls to the [HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine are supported. Prior to Windows 8, miniports must not set this flag.<br><br>This flag is valid when **Version** is set to 2 or 3. |
| STOR_PERF_INTERRUPT_MESSAGE_RANGES | This flag is used to indicate that interrupt redirection is supported. When you use this flag, you must also set the STOR_PERF_DPC_REDIRECTION flag.<br><br>This flag is valid when **Version** is set to 2 or 3. |
| STOR_PERF_ADV_CONFIG_LOCALITY | This flag is used to indicate that you should use the group and mask that pertain to the message group with the correct affinity. When you use this flag, you must also set the STOR_PERF_INTERRUPT_MESSAGE_RANGES and the STOR_PERF_DPC_REDIRECTION flags.<br><br>This flag is valid when **Version** is set to 3. |
| STOR_PERF_OPTIMIZE_FOR_COMPLETION_DURING_STARTIO | This flag is used to indicate that the miniport driver will complete I/Os concurrently with the submission of new I/Os. When you use this flag, you must also set the STOR_PERF_DPC_REDIRECTION flag.<br><br>This flag is valid when **Version** is set to 3. See remarks below. |
| STOR_PERF_DPC_REDIRECTION_CURRENT_CPU | This flag is used to indicate that you are opting into DPC Redirection (required) but the IO redirection choice is set to the CPU requesting the DPC and not the CPU originating the IO request into Storport.<br><br>When you use this flag, you must also set the STOR_PERF_DPC_REDIRECTION flag.<br><br>This flag is valid when **Version** is set to 4. |
| STOR_PERF_NO_SGL | This flag is used to indicate that miniport doesn't need SGLs to be created by storport driver for an IO request buffer. <br><br>This flag is valid when **Version** is set to 5. |

### `ConcurrentChannels`

The number of concurrent calls to the [HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine that the miniport driver and the device support. This member is only accessed when the STOR_PERF_CONCURRENT_CHANNELS flag has been set. Prior to Windows 8, miniports must not set this value.

### `FirstRedirectionMessageNumber`

When the **Flags** member has the STOR_PERF_INTERRUPT_MESSAGE_RANGES flag set, the miniport driver initializes interrupt redirection to begin with this message number. This member is only accessed when the STOR_PERF_INTERRUPT_MESSAGE_RANGES flag is set.

### `LastRedirectionMessageNumber`

When the **Flags** member has the STOR_PERF_INTERRUPT_MESSAGE_RANGES flag set, the miniport driver initializes interrupt redirection to end with this message number. This member is only accessed when the STOR_PERF_INTERRUPT_MESSAGE_RANGES flag is set.

### `DeviceNode`

When the **Flags** member has the STOR_PERF_ADV_CONFIG_LOCALITY flag set, Storport initializes this field to contain the NUMA node number in which the miniport driver's device resides.

### `Reserved`

Reserved for system use.

### `MessageTargets`

When the **Flags** member has the STOR_PERF_ADV_CONFIG_LOCALITY flag set, Storport initializes the fields of in the structures of a [GROUP_AFFINITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniport/ns-miniport-_group_affinity) array. These structures correspond to the redirection messages that are currently in use. The array itself is zero-based, but **FirstRedirectionMessageNumber** is not required to be zero. The miniport allocates this array and sets **MessageTargets** to point to it. The miniport driver must allocate a **GROUP_AFFINITY** array large enough to hold all the returned affinity masks.

## Remarks

The current version of this structure is defined by **STOR_PERF_VERSION**. Setting **Version** to this value will allow **Flags** to specify all supported optimizations.

The purpose of the STOR_PERF_DPC_REDIRECTION flag is to ensure that individual CPUs are not overwhelmed with DPC processing. When this flag is set, DPC processing is spread over multiple CPUs. If STOR_PERF_DPC_REDIRECTION_CURRENT_CPU is not set, StorPort will attempt to schedule I/O completion DPCs on the same CPU that originated the I/O.

Typically, a miniport completes I/O requests in it's [HwStorStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine and calls [StorPortNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) with the **RequestComplete** notification type. For processing I/O in this manner, the miniport will leave the STOR_PERF_OPTIMIZE_FOR_COMPLETION_DURING_STARTIO flag set in the **Flags** member allowing Storport to adjust DPC redirection.

For information about enabling message-signaled interrupts for a device, see [Enabling Message-Signaled Interrupts in the Registry](https://learn.microsoft.com/windows-hardware/drivers/kernel/enabling-message-signaled-interrupts-in-the-registry).

## See also

[StorPortInitializePerfOpts](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeperfopts)