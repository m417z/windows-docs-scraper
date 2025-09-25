## Description

The WHEA_ERROR_PACKET_FLAGS union defines the error condition reported through a [WHEA_ERROR_PACKET](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.PreviousError`

A single bit that indicates whether the hardware error packet contains information about a fatal hardware error. This error caused the operating system to generate a bug check and restart.

### `DUMMYSTRUCTNAME.CriticalEvent`

### `DUMMYSTRUCTNAME.HypervisorError`

A single bit that indicates that a hypervisor error has occurred.

### `DUMMYSTRUCTNAME.Simulated`

A single bit that indicates that the error condition was simulated.

### `DUMMYSTRUCTNAME.PlatformPfaControl`

A single bit that indicates whether WHEA or a PSHED plug-in is in control of predictive failure analysis (PFA). If this bit is set, the PSHED plug-in is in control of PFA and must set the **PlatformDirectedOffline** to bring an [ECC](https://learn.microsoft.com/windows-hardware/drivers/) memory page into an offline state.

For more information about PFA support for WHEA, see [Predictive Failure Analysis (PFA)](https://learn.microsoft.com/windows-hardware/drivers/whea/predictive-failure-analysis--pfa-).

### `DUMMYSTRUCTNAME.PlatformDirectedOffline`

A single bit that indicates whether the PSHED plug-in that performs PFA on a system component has determined if the component should be brought into an offline state. This bit is only valid if the **PlatformPfaControl** member is set.

### `DUMMYSTRUCTNAME.AddressTranslationRequired`

This field indicates that WHEA has identified this packet represents a memory error but the error data gathered by WHEA does not contain
a valid physical address. A PSHED Plug-in may perform platform specific translation on the address to allow WHEA to take action. If
this flag is set and the **RecoveryOptional** flag is 0 the system crashes with [bug check code 0x124](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x124---whea-uncorrectable-error) indicating a fatal hardware error.

### `DUMMYSTRUCTNAME.AddressTranslationCompleted`

If the **AddressTranslationRequired** bit is set, a PSHED plug-in may set this bit during its retrieve error info callback to indicate the
memory address contained in the error state has been updated to reflect a valid physical address. This will allow WHEA to perform
recovery.

### `DUMMYSTRUCTNAME.RecoveryOptional`

This field indicates that recovery is optional and the system may continue execution without further action. This flag is set
for errors where action is optional and AddressTranslationRequired is set to prevent the system from crashing if a PSHED plug-in
does not provide a translation.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved for system use.

### `AsULONG`

A ULONG representation of the contents of the **WHEA_ERROR_PACKET_FLAGS** union.

## Remarks

The WHEA_ERROR_PACKET_FLAGS union describes the error condition reported by using a [**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85)) structure.

## See also

[Predictive Failure Analysis (PFA)](https://learn.microsoft.com/windows-hardware/drivers/whea/predictive-failure-analysis--pfa-)

[**WHEA_ERROR_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff560465(v=vs.85))