## Description

The **KSDEVICE_DESCRIPTOR** structure describes the characteristics of a particular device.

## Members

### `Dispatch`

A pointer to the client dispatch table for this device. This dispatch table contains client dispatch functions for PNP messages such as **Add**, **Start**, **Stop**, **Remove**. Clients are not required to supply a dispatch table unless they want to receive callbacks for the PNP messages described in the dispatch table. Any member of the dispatch table can be **NULL** to indicate that the client does not want to receive notification for that particular message. For more information, see [**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch).

### `FilterDescriptorsCount`

This member contains the number of filter descriptors for this device that will be provided in the **FilterDescriptors** member. Zero is a legal value for this member; clients can create filter factories dynamically with the [KsCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatefilterfactory) function instead of statically describing them in the device descriptor.

### `FilterDescriptors`

A pointer to an array of filter descriptors that describe filters that can be created by this device. This member may be **NULL** if **FilterDescriptorsCount** is zero. For more information, see [**KSFILTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor).

### `Version`

A value of type ULONG. This should be one and only one of the values in the following table, or set to zero if writing a pre-version 0x100 driver.

| Value | Description |
|---|---|
| KSDEVICE_DESCRIPTOR_VERSION | Indicates support of the [AVStrMiniDeviceQueryInterface](https://learn.microsoft.com/previous-versions/ff554290(v=vs.85)) dispatch of [KSDEVICE_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch). |
| KSDEVICE_DESCRIPTOR_VERSION_2 | Indicates support of the **Flags** member of KSDEVICE_DESCRIPTOR. |

### `Flags`

A value of type ULONG. There is only one flag currently defined.

| Flag | Description |
|---|---|
| KSDEVICE_FLAG_ENABLE_REMOTE_WAKEUP | Indicates that the device supports remote wakeup. |

### `Alignment`

## Remarks

Most often, this structure is used in conjunction with [KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver) in the client's **DriverEntry** function to initialize the device. This structure is also used to manually initialize or create devices with the [KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice) and [KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice) functions.

If you set **Version** to KSDEVICE_DESCRIPTOR_VERSION_2 and run your driver on an early version of AVStream that does not support **Flags**, all flags will be considered to be zero.

Similarly, using an earlier version descriptor on later versions of AVStream causes no flags to be specified.

## See also

[**KSDEVICE_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice_dispatch)

[**KSFILTER_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_descriptor)

[KsCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatedevice)

[KsInitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedevice)

[KsInitializeDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksinitializedriver)