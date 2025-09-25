# NVME_FEATURES enumeration

## Description

Contains values that indicate which feature should be retrieved or configured by the **NVME_ADMIN_COMMAND_GET_FEATURES** and **NVME_ADMIN_COMMAND_SET_FEATURES** Admin commands.

## Constants

### `NVME_FEATURE_ARBITRATION`

The Arbitration feature that controls command processing by defining the number of commands from a certain priority that may be executed.

### `NVME_FEATURE_POWER_MANAGEMENT`

The Power Management feature that allows the host to configure the power state.

### `NVME_FEATURE_LBA_RANGE_TYPE`

The Logical Block Addressing (LBA) Range Type feature that indicates the type and attributes of LBA ranges that are part of the specified namespace.

The LBA range information is used by a driver to determine if it can utilize a particular LBA range. The information is not exposed to higher level software.

### `NVME_FEATURE_TEMPERATURE_THRESHOLD`

The Temperature Threshold feature that maintains an over-temperature threshold or an under-temperature threshold for the nine temperature sensors.

### `NVME_FEATURE_ERROR_RECOVERY`

The Error Recovery feature that controls the error recovery attributes.

### `NVME_FEATURE_VOLATILE_WRITE_CACHE`

The Volatile Write Cache feature that controls whether the volatile write cache is enabled.

### `NVME_FEATURE_NUMBER_OF_QUEUES`

The Number of Queues feature that maintains the number of queues that the host requests for this controller.

### `NVME_FEATURE_INTERRUPT_COALESCING`

The Interrupt Coalescing feature that configures the interrupt coalescing settings for the controller.

### `NVME_FEATURE_INTERRUPT_VECTOR_CONFIG`

The Interrupt Vector Configuration feature that configures settings specific to a particular interrupt vector.

### `NVME_FEATURE_WRITE_ATOMICITY`

The Write Atomicity Normal feature that controls the operation of the Atomic Write Unit Normal (AWUN) and Namespace Atomic Write Unit Normal (NAWUN) parameters.

### `NVME_FEATURE_ASYNC_EVENT_CONFIG`

The Asynchronous Event Configuration feature that controls the events that trigger an asynchronous event notification to the host.

### `NVME_FEATURE_AUTONOMOUS_POWER_STATE_TRANSITION`

The Autonomous Power State Transition feature that configures the settings for autonomous power state transitions.

### `NVME_FEATURE_HOST_MEMORY_BUFFER`

The Host Memory Buffer feature that provides a mechanism for the host to allocate a portion of host memory for the controller to use exclusively.

### `NVME_FEATURE_TIMESTAMP`

The Timestamp feature.

### `NVME_FEATURE_KEEP_ALIVE`

The Keep Alive feature.

### `NVME_FEATURE_HOST_CONTROLLED_THERMAL_MANAGEMENT`

The Controlled Thermal Management feature.

### `NVME_FEATURE_NONOPERATIONAL_POWER_STATE`

The Non-Operational Power State feature.

### `NVME_FEATURE_NVM_SOFTWARE_PROGRESS_MARKER`

The Software Progress Marker feature that indicates the load count of pre-boot software and is persistent across power states.

### `NVME_FEATURE_NVM_HOST_IDENTIFIER`

The Host Identifier feature that allows the host to register a Host Identifier with the controller.

The Host Identifier is used by the controller to determine whether other controllers in the NVM Subsystem are associated with the same host and is only required to be initialized if reservations are supported.

### `NVME_FEATURE_NVM_RESERVATION_NOTIFICATION_MASK`

The Reservation Notification Mask feature that controls the masking of reservation notifications on a per namespace basis.

### `NVME_FEATURE_NVM_RESERVATION_PERSISTANCE`

The Reservation Persistence feature that allows modification of the Persist Through Power Loss (PTPL) state.

## Remarks

In the **NVME_ADMIN_COMMAND_GET_FEATURES** and **NVME_ADMIN_COMMAND_SET_FEATURES** Admin commands, the feature is specified in the Feature Identifier (**FID**) member of the [NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features) and [NVME_CDW10_SET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features) structures.

## See also

[NVME_CDW10_GET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_features)
[NVME_CDW10_SET_FEATURES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_set_features)