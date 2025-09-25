# IPortWavePciStream::GetMapping

## Description

The `GetMapping` method obtains a mapping from the port driver and associates a tag with the mapping.

## Parameters

### `Tag` [in]

Specifies a tag value to associate with the mapping. The port driver can use this tag in a subsequent [IMiniportWavePciStream::RevokeMappings](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-revokemappings) call to identify the mapping in the list of mappings to be revoked. The miniport driver uses the tag to identify the mapping in the [IPortWavePciStream::ReleaseMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-releasemapping) call that releases the mapping.

### `PhysicalAddress` [out]

Output pointer for the physical address. This parameter points to a caller-allocated pointer variable into which the method writes the physical address of the mapping. Specify a valid, non-NULL pointer value for this parameter.

### `VirtualAddress` [out]

Output pointer for the virtual address. This parameter points to a caller-allocated pointer variable into which the method writes the virtual address of the mapping. Specify a valid, non-NULL pointer value for this parameter.

### `ByteCount` [out]

Output pointer for the byte count. This parameter points to a caller-allocated ULONG variable into which the method writes the number of bytes in the mapping. Specify a valid, non-NULL pointer value for this parameter.

### `Flags` [out]

Output pointer for the status flag. This parameter points to a caller-allocated ULONG variable into which the method writes a status flag. Specify a valid, non-NULL pointer value for this parameter. A nonzero flag value indicates that the mapping acquired in this call is the last mapping in an I/O packet. This flag can be used to signal that the hardware should interrupt the miniport driver when it is done with this mapping. In response to the interrupt, the miniport driver can obtain new mappings to deliver to the hardware. The miniport driver is not obligated to use the flag in this way.

## Return value

`GetMapping` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | A mapping is not immediately available, but the port driver will call [IMiniportWavePciStream::MappingAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-mappingavailable) when a mapping does become available. |

## Remarks

Mappings obtained through the `GetMapping` method should be released by calling [IPortWavePciStream::ReleaseMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-releasemapping) unless they are revoked by the port driver. The port driver can revoke mappings by calling the stream's [IMiniportWavePciStream::RevokeMappings](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-revokemappings) method.

The buffer storage for a stream that is played back through a miniport driver's rendering pin is attached to one or more IRPs. Each IRP contains a portion of the buffer storage for the stream. Each IRP's buffer storage is contiguous in virtual memory, but the memory pages that comprise the buffer do not in general map to contiguous locations in physical memory. Although a driver can use programmed I/O to access the buffer through its mapping into virtual memory, a DMA controller requires physical mappings instead.

The WavePci port driver uses the `GetMapping` method to expose the buffer to the miniport driver as a sequence of physical mappings. A typical mapping is one memory page or less in size, although a mapping can exceed the page size if two or more pages happen to occupy adjacent locations in physical memory.

The initial call to `GetMapping` outputs the mapping at the beginning of the buffer. Each successive call to `GetMapping` presents the next sequential mapping in the buffer. After reaching the end of the buffer, the next `GetMapping` call outputs the mapping at the beginning of the buffer and the mapping sequence repeats.

The kernel-mode virtual-memory address of the mapping is output through the *VirtualAddress* parameter. The miniport driver uses this address to access the mapping under direct program control. The page that contains the mapping is locked and no page fault can occur when the driver accesses the mapping. The audio device's bus-master DMA controller uses the address that is output through the *PhysicalAddress* parameter to access the mapping.

The *Tag* parameter is a PVOID value that the caller chooses to uniquely identify the mapping:

* The port driver might use this tag to identify the mapping in a subsequent call to **IMiniportWavePciStream::RevokeMappings**.
* The miniport driver can use this tag to identify the mapping in a subsequent call to **IPortWavePciStream::ReleaseMapping**.

Although *Tag* is defined to be of type PVOID, the port driver never attempts to use this value as a pointer and does not require that it be a valid pointer.

A typical WavePci miniport driver maintains a record of each mapping that it receives. The tag might be a pointer to a record or an index into an array of records, for example, depending on the implementation. The only requirement for a tag is that it be a value that can be cast to type PVOID.

The *Flags* parameter indicates whether the call to `GetMapping` retrieved the final mapping in the portion of the audio data buffer that is attached to the current mapping IRP. When *Flags* indicates that a mapping is the last mapping in an IRP, a miniport driver can arm a hardware interrupt to fire when the miniport driver finishes playing that mapping. When the interrupt fires, this event informs the miniport driver that it needs to acquire more mappings to add to its DMA queue. The *Flags* parameter is typically used by a miniport driver that manages a single playback stream from the [KMixer system driver](https://learn.microsoft.com/windows-hardware/drivers/audio/kernel-mode-wdm-audio-components). KMixer uses several mapping IRPs (a minimum of three in the current KMixer implementation) to buffer a single playback stream. Thus, if the miniport driver generates a hardware interrupt each time the DMA controller finishes with the final mapping in an IRP, interrupts should occur frequently enough to keep the DMA queue from starving.

The *Flags* parameter is typically ignored by miniport drivers that manage one or more DirectSound hardware-accelerated streams (see [DirectSound Hardware Acceleration in WDM Audio](https://learn.microsoft.com/windows-hardware/drivers/audio/directsound-hardware-acceleration-in-wdm-audio)). In the case of a DirectSound buffer, the entire buffer can be attached to a single IRP. If the buffer is large and the miniport driver schedules a hardware interrupt only when it reaches the end of the buffer, interrupts will occur so far apart that the DMA queue might starve. In addition, if the driver is managing a large number of streams, scheduling a hardware interrupt each time the *Flags* parameter signals a final-mapping condition on a stream might generate so many interrupts that performance can be degraded. In these circumstances, the miniport driver should not rely on hardware interrupts to acquire mappings. Instead, it should schedule timer DPCs to occur at regular intervals to acquire mappings.

A miniport driver is most likely to call `GetMapping` during a call to the miniport stream object's **SetState**, **Service**, or **MappingAvailable** method (see [IMiniportWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavepcistream)).

To avoid potential deadlocks, the adapter driver must avoid holding a spin lock during its call to `GetMapping`. See the ac97 sample audio driver in the Microsoft Windows Driver Kit (WDK) for a code example that uses a spin lock to serialize accesses to shared data structures and peripherals in a multiprocessor system. The sample code calls [KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock) before calling `GetMapping` and calls [KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock) after calling `GetMapping`. Between the calls to release and acquire the spin lock, the driver thread must not assume that it has exclusive access to the data or peripherals that are guarded by the spin lock. The [Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/what-s-new-in-driver-development) tool checks for active spin locks during calls to `GetMapping`; if it detects one, it generates a 0xC4 (deadlock detection) bug check.

Although the size of a typical mapping is one memory page or less, a single mapping can exceed the page size if a portion of an audio buffer happens to occupy two or more contiguous pages in physical memory. Larger mappings can create problems for DMA hardware with design flaws that limit the block size. For example, if a DMA controller can handle a maximum block size of a single page, and `GetMapping` outputs a mapping that is larger than a page, the miniport driver must split the mapping into smaller blocks that the DMA hardware can handle. If the resulting number of blocks exceeds the number of available map registers in the DMA hardware, the driver cannot queue all of the blocks in a single scatter/gather DMA operation. When this occurs, the driver must keep track of the unqueued portion of the mapping and initiate DMA transfers of the remaining blocks at a later time when additional map registers become available.

In Windows 98/Me, Windows 2000, Windows XP, and Windows Server 2003, the `GetMapping` method never outputs a mapping that spans more than 16 pages. This limit might change in future Windows releases.

For more information about mappings, see [WavePci Latency](https://learn.microsoft.com/windows-hardware/drivers/audio/wavepci-latency).

## See also

[IMiniportWavePciStream::GetAllocatorFraming](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-getallocatorframing)

[IMiniportWavePciStream::MappingAvailable](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-mappingavailable)

[IMiniportWavePciStream::RevokeMappings](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavepcistream-revokemappings)

[IPortWavePciStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportwavepcistream)

[IPortWavePciStream::ReleaseMapping](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportwavepcistream-releasemapping)

[KeAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keacquirespinlock)

[KeReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kereleasespinlock)