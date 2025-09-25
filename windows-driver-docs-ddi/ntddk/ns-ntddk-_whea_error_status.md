## Description

The **WHEA_ERROR_STATUS** union describes generic error codes that are abstracted from the data contained in implementation-specific error registers.

## Members

### `ErrorStatus`

A ULONGLONG representation of the contents of the **WHEA_ERROR_STATUS** union.

### `DUMMYSTRUCTNAME`

Defines the **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.Reserved1`

Reserved for system use.

### `DUMMYSTRUCTNAME.ErrorType`

The type of hardware error that occurred.

Possible values are:

| Value | Description |
|---|---|
| ERRTYP_BUS | A bus error. |
| ERRTYP_CACHE | A cache error. |
| ERRTYP_FLOW | An overflow or underflow of a queue that is internal to the component. |
| ERRTYP_FUNCTION | An error in one or more functional units. |
| ERRTYP_IMPROPER | An improper access error. |
| ERRTYP_INTERNAL | An error internal to the component. |
| ERRTYP_LOSSOFLOCKSTEP | A loss of lockstep. |
| ERRTYP_MAP | The virtual address was not found on IO-TLB or IO-PDIR. |
| ERRTYP_MEM | A memory error. |
| ERRTYP_PARITY | A bus parity error. |
| ERRTYP_PATHERRORA bus path error. |
| ERRTYP_POISONED | A read operation was issued to data that has been corrupted. |
| ERRTYP_PROTOCOL | A bus protocol error. |
| ERRTYP_RESPONSE | A response was received that was not associated with a request. |
| ERRTYP_SELFTEST | The component failed self test. |
| ERRTYP_TIMEOUT | A bus timeout error. |
| ERRTYP_TLB | A translation lookaside buffer error. |
| ERRTYP_UNIMPL | An access to a memory address that is not mapped to any component. |

### `DUMMYSTRUCTNAME.Address`

A single bit that indicates if the error was detected on the address signals or during the address portion of the transaction.

### `DUMMYSTRUCTNAME.Control`

A single bit that indicates if the error was detected on the control signals or during the control portion of the transaction.

### `DUMMYSTRUCTNAME.Data`

A single bit that indicates if the error was detected on the data signals or during the data portion of the transaction.

### `DUMMYSTRUCTNAME.Responder`

A single bit that indicates that the error was detected by the responder of the transaction.

### `DUMMYSTRUCTNAME.Requester`

A single bit that indicates that the error was detected by the requester of the transaction.

### `DUMMYSTRUCTNAME.FirstError`

A single bit that indicates that the error is the first error to occur if multiple errors are logged for a section type. Setting of this bit is optional.

### `DUMMYSTRUCTNAME.Overflow`

A single bit that indicates that additional errors occurred but were not logged due to an overflow of the logging resources.

### `DUMMYSTRUCTNAME.Reserved2`

Reserved for system use.

## Remarks

The **WHEA_ERROR_STATUS** union provides the capability to abstract information from implementation-specific error registers into generic error codes so that the operating system can process the errors without an intimate knowledge of the underlying platform. This union is derived from the Error Status section of the [Intel Itanium Processor Family System Abstraction Layer Specification](https://www.intel.com/content/dam/www/public/us/en/documents/specification-updates/itanium-system-abstraction-layer-specification.pdf).

A **WHEA_ERROR_STATUS** union is contained within the [WHEA_MEMORY_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section), [WHEA_PCIXBUS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section), and [WHEA_PCIXDEVICE_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section) structures.

## See also

[WHEA_MEMORY_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_memory_error_section)

[WHEA_PCIXBUS_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixbus_error_section)

[WHEA_PCIXDEVICE_ERROR_SECTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_pcixdevice_error_section)