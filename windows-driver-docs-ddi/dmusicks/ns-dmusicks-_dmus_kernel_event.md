# _DMUS_KERNEL_EVENT structure

## Description

The DMUS_KERNEL_EVENT structure is used to package time-stamped music events.

## Members

### `bReserved`

 Miniport drivers should not modify this member. Reserved for future use. Do not use.

### `cbStruct`

 Miniport drivers should not modify this member.
This member specifies the size of the DMUS_KERNEL_EVENT structure itself and could change in the future.

### `cbEvent`

Specifies the unrounded number of event bytes referred to by **uData**.

### `usChannelGroup`

Specifies which channel group (set of 16 MIDI channels) receives or originated this event. This is unique only within the target MIDI device (miniport driver).

### `usFlags`

Specifies whether an event is a package and whether this event concludes the message. A package encapsulates a list of events that should be dealt with atomically. This member is a bitfield that can be set to the bitwise OR of one or more of the following flag bits:

#### DMUS_KEF_EVENT_COMPLETE (zero)

Specifies messages in which the entire message is contained either in **uData.abData** or in the buffer pointed to by **uData.pbData**. The former includes all short messages, and potentially includes very brief SysEx messages (see Microsoft Windows SDK documentation) as well. Keep in mind that **sizeof**(PBYTE) can be 8 instead of 4 on 64-bit versions of Windows.

#### DMUS_KEF_EVENT_INCOMPLETE

Specifies that this event is an incomplete package or SysEx message (see Windows SDK documentation). This flag specifies that the message continues beyond this event. During MIDI capture, the miniport driver can send "uncooked" MIDI events (raw MIDI input data) to the capture sink by specifying this flag.

#### DMUS_KEF_PACKAGE_EVENT

Specifies that this event is a package. The **uData.pPackageEvt** field contains a pointer to a chain of events which should be dealt with atomically.

### `ullPresTime100ns`

Specifies the presentation time for this event. This 64-bit value is expressed in 100-nanosecond units. The master clock should be used to evaluate this presentation time.

### `ullBytePosition`

8 16

### `pNextEvt`

Pointer to the next event in the list, or **NULL** if no event follows. This facilitates passing chains of identically time-stamped messages to the miniport driver. Additionally, hardware that does its own mixing can receive or transmit groups of messages at one time.

### `uData`

### `uData.abData`

A byte array containing **cbEvent** bytes of event data. The event data are typically MIDI status and data bytes. This member of **uData** is used if **cbEvent** is less than or equal to **sizeof**(PBYTE).

### `uData.pbData`

Pointer to a buffer containing **cbEvent** bytes of event data. The event data are typically MIDI status and data bytes. This member of **uData** is used if **uFlags** is set to DMUS_KEF_EVENT_COMPLETE and **cbEvent** is greater than **sizeof**(PBYTE).

### `uData.pPackageEvt`

Pointer to a chain of events, which is in the form of a linked list of DMUS_KERNEL_EVENT structures. The event data typically consist of MIDI status and data bytes. The events in the list are to be handled together. This member of **uData** is used if **uFlags** is set to DMUS_KEF_PACKAGE_EVENT.

## Remarks

The DMUS_KERNEL_EVENT structure is used by WDM audio drivers that provide kernel streaming support for DirectMusic.

While capturing a MIDI stream, the DMus port driver calls the [IAllocatorMXF::GetMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iallocatormxf-getmessage) method to retrieve DMUS_KERNEL_EVENT structures to hold the captured data. While rendering a MIDI stream, the port driver calls the [IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage) method to discard DMUS_KERNEL_EVENT structures as it finishes reading them. For more information, see [MIDI Transport](https://learn.microsoft.com/windows-hardware/drivers/audio/midi-transport).

In the case of MIDI capture, the DMUS_KERNEL_EVENT structure can be packaged with single, multiple, or fragmentary MIDI messages. The **usFlags** member should be set to DMUS_KEF_EVENT_INCOMPLETE unless it is a single complete MIDI message. This structure also contains:

* A time stamp relative to the master clock (ullPresTime100Ns)
* Extended channel information (usChannelGroup)

Mapping to the correct DLS instrument is implicit in the triplet of

<*pin*, *channel_group*, *channel*>

Presentation time does not advance during the states KSSTATE_PAUSE and KSSTATE_STOP, and is reset during KSSTATE_STOP. For more information, see [KS Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-clocks).

## See also

[IAllocatorMXF::GetMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-iallocatormxf-getmessage)

[IMXF::PutMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dmusicks/nf-dmusicks-imxf-putmessage)