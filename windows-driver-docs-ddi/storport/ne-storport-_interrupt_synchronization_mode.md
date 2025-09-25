# _INTERRUPT_SYNCHRONIZATION_MODE enumeration

## Description

The INTERRUPT_SYNCHRONIZATION_MODE enumerator specifies the interrupt synchronization mode.

## Constants

### `InterruptSupportNone`

MSI interrupts are not supported.

### `InterruptSynchronizeAll`

The Storport driver serializes all message signaled interrupts using a single interrupt spin lock. When an interrupt occurs, the Storport driver calls the miniport driver's [**HwMSInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine) routine at DIRQL after acquiring the interrupt spin lock.

### `InterruptSynchronizePerMessage`

The miniport driver serializes message signaled interrupts on a per message basis. In the synchronization per message mode, the Storport driver calls the miniport driver's [**HwMSInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine) routine at DIRQL holding the interrupt spin lock of the corresponding message. For more on the behavior of this synchronization mode, see the remarks section for HwMSInterruptRoutine.

## Remarks

Miniport drivers define the HBA's interrupt synchronization mode by assigning one of the INTERRUPT_SYNCHRONIZATION_MODE enumeration values to the **InterruptSynchronizationMode** member of the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information) structure.

## See also

[**HwMSInterruptRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_message_signaled_interrupt_routine)

[**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_port_configuration_information)

[**StorPortAcquireMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquiremsispinlock)

[**StorPortReleaseMSISpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportreleasemsispinlock)