# NVME_CONTROLLER_MEMORY_BUFFER_SIZE structure

## Description

Defines the size of the optional Controller Memory Buffer register, and is used in the **CMBSZ** field of the [NVME_CONTROLLER_REGISTERS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_registers) structure.

If the controller does not support the Controller Memory Buffer feature, the **CMBSZ** field is cleared to `0h`.

The location of the Controller Memory Buffer is specified in the **CMBLOC** field of **NVME_CONTROLLER_REGISTERS**.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.SQS`

Indicates whether the controller supports Admin and I/O Submission Queues in the Controller Memory Buffer.

When this value is set to `1`, the controller supports Admin and I/O Submission Queues in the Controller Memory Buffer.
When this value is cleared to `0`, all Submission Queues will be placed in host memory.

### `DUMMYSTRUCTNAME.CQS`

Indicates whether the controller supports Admin and I/O Completion Queues in the Controller Memory Buffer.

When this value is set to `1`, the controller supports Admin and I/O Completion Queues in the Controller Memory Buffer.
When this value is cleared to `0`, all Completion Queues will be placed in host memory.

### `DUMMYSTRUCTNAME.LISTS`

Indicates whether the controller supports Physical Region Page (PRP) and Scatter Gather Lists (SGL) in the Controller Memory Buffer.

When this value is set to `1`, the controller supports PRP Lists in the Controller Memory Buffer. If the value is set to `1` and SGLs are supported by the controller, the controller supports SGLs in the Controller Memory Buffer. If this bit is set to `1`, the Submission Queue Support (**SQS**) field will be set to `1`.

When this value is cleared to `0`, all PRP Lists and SGLs will be placed in host memory.

### `DUMMYSTRUCTNAME.RDS`

Indicates whether the controller supports data and metadata in the Controller Memory Buffer for commands, such as the Read command, that transfer data from the controller to the host.

When this value is set to `1`, the controller supports data and metadata in the Controller Memory Buffer for commands that transfer data from the controller to the host.

When this value is cleared to `0`, all data and metadata for commands that transfer data from the controller to the host will be transferred to host memory.

### `DUMMYSTRUCTNAME.WDS`

Indicates whether the controller supports data and metadata in the Controller Memory Buffer for commands, such as the Write command, that transfer data from the host to the controller.

When this value is set to `1`, the controller supports data and metadata in the Controller Memory Buffer for commands that transfer data from the host to the controller.

When this value is cleared to `0`, all data and metadata for commands that transfer data from the host to the controller will be transferred from host memory.

### `DUMMYSTRUCTNAME.Reserved`

### `DUMMYSTRUCTNAME.SZU`

A [NVME_CMBSZ_SIZE_UNITS](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_cmbsz_size_units) value that indicates the granularity of the Size **SZ** field.

### `DUMMYSTRUCTNAME.SZ`

Indicates the size of the Controller Memory Buffer available for use by the host. The size is in multiples of the Size Unit **SZU**.

If the Offset (the **OFST** field in the [NVME_CONTROLLER_MEMORY_BUFFER_LOCATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_memory_buffer_location) structure) + Size (**SZ**) exceeds the length of the specified Base Address Register (the **BIR** field in the [NVME_CONTROLLER_MEMORY_BUFFER_LOCATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_memory_buffer_location) structure), the size available to the host is limited by the length of the Base Address Register.

### `AsUlong`

## Remarks

## See also

- [NVME_CONTROLLER_MEMORY_BUFFER_LOCATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_memory_buffer_location)