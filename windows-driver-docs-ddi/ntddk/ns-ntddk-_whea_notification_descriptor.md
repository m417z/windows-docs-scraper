## Description

The **WHEA_NOTIFICATION_DESCRIPTOR** structure describes the notification mechanism that is used by an error source.

## Members

### `Type`

The type of notification mechanism that is used by the error source. This can be one of the following possible values.

| Value | Meaning |
|---|---|
| **WHEA_NOTIFICATION_TYPE_EXTERNALINTERRUPT** | The error source notifies the LLHEH for the error source by means of an external interrupt. |
| **WHEA_NOTIFICATION_TYPE_LOCALINTERRUPT** | The error source notifies the LLHEH for the error source by means of a local interrupt. |
| **WHEA_NOTIFICATION_TYPE_NMI** | The error source notifies the LLHEH for the error source by means of a nonmaskable interrupt (NMI). |
| **WHEA_NOTIFICATION_TYPE_POLLED** | The low-level hardware error handler (LLHEH)for the error source must periodically poll the error status registers to check for an error condition. |
| **WHEA_NOTIFICATION_TYPE_SCI** | The error source notifies the LLHEH for the error source by means of a service control interrupt (SCI). |

### `Length`

The size, in bytes, of the **WHEA_NOTIFICATION_DESCRIPTOR** structure.

### `Flags`

A WHEA_NOTIFICATION_FLAGS union that indicates which of the members of the **WHEA_NOTIFICATION_DESCRIPTOR** structure can be written to by the operating system. The WHEA_NOTIFICATION_FLAGS union is defined as follows:

```cpp
typedef union _WHEA_NOTIFICATION_FLAGS {
  struct {
    USHORT  PollIntervalRW:1;
    USHORT  SwitchToPollingThresholdRW:1;
    USHORT  SwitchToPollingWindowRW:1;
    USHORT  ErrorThresholdRW:1;
    USHORT  ErrorThresholdWindowRW:1;
    USHORT  Reserved:11;
  };
  USHORT  AsUSHORT;
} WHEA_NOTIFICATION_FLAGS, *PWHEA_NOTIFICATION_FLAGS
```

| Value | Meaning |
|---|---|
| **AsUSHORT** | A USHORT representation of the contents of the WHEA_NOTIFICATION_FLAGS union. |
| **ErrorThresholdRW** | A single bit that indicates that the operating system can write to the **u.***xxx***.ErrorThreshold** members of the WHEA_NOTIFICATION_DESCRIPTOR structure. |
| **ErrorThresholdWindowRW** | A single bit that indicates that the operating system can write to the **u.***xxx***.ErrorThresholdWindow** members of the WHEA_NOTIFICATION_DESCRIPTOR structure. |
| **PollIntervalRW** | A single bit that indicates that the operating system can write to the **u.***xxx***.PollInterval** members of the WHEA_NOTIFICATION_DESCRIPTOR structure. |
| **Reserved** | Reserved for system use. |
| **SwitchToPollingThresholdRW** | A single bit that indicates that the operating system can write to the **u.***xxx***.SwitchToPollingThreshold** members of the WHEA_NOTIFICATION_DESCRIPTOR structure. |
| **SwitchToPollingWindowRW** | A single bit that indicates that the operating system can write to the **u.***xxx***.SwitchToPollingWindow** members of the WHEA_NOTIFICATION_DESCRIPTOR structure. |

### `u`

A union of structures that are specific to each different type of notification mechanism.

### `u.Polled`

A structure that describes the notification mechanism when the **Type** member is set to WHEA_NOTIFICATION_TYPE_POLLED.

### `u.Polled.PollInterval`

The interval, in milliseconds, that the LLHEH for the error source should poll the error status registers to check for an error condition.

### `u.Interrupt`

A structure that describes the notification mechanism when the **Type** member is set to WHEA_NOTIFICATION_TYPE_EXTERNALINTERRUPT.

### `u.Interrupt.PollInterval`

The interval, in milliseconds, that the LLHEH for the error source should poll the error status registers to check for an error condition if the error source is switched out of interrupt mode.

### `u.Interrupt.Vector`

The interrupt vector for the error source.

### `u.Interrupt.SwitchToPollingThreshold`

The number of errors that must occur within the time specified by the **SwitchToPollingWindow** member before the error source is switched to polling mode.

### `u.Interrupt.SwitchToPollingWindow`

The window of time, in seconds, in which the number of errors specified by the **SwitchToPollingThreshold** member must occur before the error source is switched to polling mode.

### `u.Interrupt.ErrorThreshold`

The number of errors that must occur within the time specified by the **ErrorThresholdWindow** member before an error from the error source is processed by the operating system.

### `u.Interrupt.ErrorThresholdWindow`

The window of time, in seconds, in which the number of errors specified by the **ErrorThreshold** member must occur before an error from the error source is processed by the operating system.

### `u.LocalInterrupt`

A structure that describes the notification mechanism when the **Type** member is set to WHEA_NOTIFICATION_TYPE_LOCALINTERRUPT.

### `u.LocalInterrupt.PollInterval`

The interval, in milliseconds, that the LLHEH for the error source should poll the error status registers to check for an error condition if the error source is switched out of interrupt mode.

### `u.LocalInterrupt.Vector`

The interrupt vector for the error source.

### `u.LocalInterrupt.SwitchToPollingThreshold`

The number of errors that must occur within the time specified by the **SwitchToPollingWindow** member before the error source is switched to polling mode.

### `u.LocalInterrupt.SwitchToPollingWindow`

The window of time, in seconds, in which the number of errors specified by the **SwitchToPollingThreshold** member must occur before the error source is switched to polling mode.

### `u.LocalInterrupt.ErrorThreshold`

The number of errors that must occur within the time specified by the **ErrorThresholdWindow** member before an error from the error source is processed by the operating system.

### `u.LocalInterrupt.ErrorThresholdWindow`

The window of time, in seconds, in which the number of errors specified by the **ErrorThreshold** member must occur before an error from the error source is processed by the operating system.

### `u.Sci`

 A structure that describes the notification mechanism when the **Type** member is set to WHEA_NOTIFICATION_TYPE_SCI.

### `u.Sci.PollInterval`

The interval, in milliseconds, that the LLHEH for the error source should poll the error status registers to check for an error condition if the error source is switched out of interrupt mode.

### `u.Sci.Vector`

The interrupt vector for the error source.

### `u.Sci.SwitchToPollingThreshold`

The number of errors that must occur within the time specified by the **SwitchToPollingWindow** member before the error source is switched to polling mode.

### `u.Sci.SwitchToPollingWindow`

The window of time, in seconds, in which the number of errors specified by the **SwitchToPollingThreshold** member must occur before the error source is switched to polling mode.

### `u.Sci.ErrorThreshold`

The number of errors that must occur within the time specified by the **ErrorThresholdWindow** member before an error from the error source is processed by the operating system.

### `u.Sci.ErrorThresholdWindow`

The window of time, in seconds, in which the number of errors specified by the **ErrorThreshold** member must occur before an error from the error source is processed by the operating system.

### `u.Nmi`

A structure that describes the notification mechanism when the **Type** member is set to WHEA_NOTIFICATION_TYPE_NMI.

### `u.Nmi.PollInterval`

The interval, in milliseconds, that the LLHEH for the error source should poll the error status registers to check for an error condition if the error source is switched out of interrupt mode.

### `u.Nmi.Vector`

The interrupt vector for the error source.

### `u.Nmi.SwitchToPollingThreshold`

The number of errors that must occur within the time specified by the **SwitchToPollingWindow** member before the error source is switched to polling mode.

### `u.Nmi.SwitchToPollingWindow`

The window of time, in seconds, in which the number of errors specified by the **SwitchToPollingThreshold** member must occur before the error source is switched to polling mode.

### `u.Nmi.ErrorThreshold`

The number of errors that must occur within the time specified by the **ErrorThresholdWindow** member before an error from the error source is processed by the operating system.

### `u.Nmi.ErrorThresholdWindow`

The window of time, in seconds, in which the number of errors specified by the **ErrorThreshold** member must occur before an error from the error source is processed by the operating system.

### `u.Sea`

### `u.Sea.PollInterval`

### `u.Sea.Vector`

### `u.Sea.SwitchToPollingThreshold`

### `u.Sea.SwitchToPollingWindow`

### `u.Sea.ErrorThreshold`

### `u.Sea.ErrorThresholdWindow`

### `u.Sei`

### `u.Sei.PollInterval`

### `u.Sei.Vector`

### `u.Sei.SwitchToPollingThreshold`

### `u.Sei.SwitchToPollingWindow`

### `u.Sei.ErrorThreshold`

### `u.Sei.ErrorThresholdWindow`

### `u.Gsiv`

### `u.Gsiv.PollInterval`

### `u.Gsiv.Vector`

### `u.Gsiv.SwitchToPollingThreshold`

### `u.Gsiv.SwitchToPollingWindow`

### `u.Gsiv.ErrorThreshold`

### `u.Gsiv.ErrorThresholdWindow`

## Remarks

A **WHEA_NOTIFICATION_DESCRIPTOR** structure is contained within the [**WHEA_GENERIC_ERROR_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor) and [WHEA_XPF_CMC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cmc_descriptor) structures.

## See also

[**WHEA_GENERIC_ERROR_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_generic_error_descriptor)

[**WHEA_XPF_CMC_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_xpf_cmc_descriptor)