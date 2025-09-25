# ComDBGetCurrentPortUsage function

## Description

**ComDBGetCurrentPortUsage** returns information about the COM port numbers that are currently logged as "in use" in the COM port database.

## Parameters

### `HComDB` [in]

Handle to the COM port database that was returned by [ComDBOpen](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbopen).

### `Buffer` [out, optional]

Pointer to a caller-allocated buffer in which the routine returns information about COM port number. See the Remarks section for more information.

### `BufferSize` [in]

Specifies the size, in bytes, of a caller-allocated buffer at *Buffer*.

### `ReportType` [in]

Specifies one of the following flags.

| Flag | Meaning |
| --- | --- |
| CDB_REPORT_BITS | The routine returns a bit array at *Buffer* that specifies port number usage. |
| CDB_REPORT_BYTES | The routine returns a byte array at *Buffer* that specifies port number usage. |

### `MaxPortsReported` [out, optional]

Pointer to the value that the routine uses to return the number of ports for which the routine returns information at *Buffer*. See the Remarks section for more information.

## Return value

**ComDBGetCurrentPortUsage** returns one of the following status values.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The routine successfully returned port number usage information. |
| **ERROR_INVALID_PARAMETER** | One of the following is true: The specified handle to the COM port database is not valid. Both *Buffer* and *MaxPortsReports* are **NULL**. *ReportType* is not valid. |
| **ERROR_NOT_CONNECTED** | The routine could not access the database. To get extended error information, call **GetLastError**. |

## Remarks

By setting *Buffer* to **NULL** and *MaxPortsReported* to a valid pointer, a caller can determine the current COM port database size, which is the number of COM port numbers that are currently arbitrated in the database. In this case, the routine sets **MaxPortsReported* to the database size. *ReportType* is not used.

If *Buffer* is non-**NULL** and *ReportType* is valid, the routine does the following:

* If *ReportType* is CDB_REPORT_BITS, the routine returns a bit array that specifies port number usage. Each bit in the output buffer corresponds to a port number. Using a zero-based index, bit zero of byte zero at *Buffer* corresponds to COM1, bit 1 corresponds to COM2, and so on. A bit value of 1 indicates that the port number is in use and a value of zero indicates the port number is not in use. The number of port numbers for which the routine returns usage information is the minimum of the current database size and the number of bits in the buffer (*BufferSize**8). If *MaxPortsReported* is non-**NULL**, the routine also sets **MaxPortsReported* to the number of port numbers for which the routine returns usage information. If BufferSize is zero, no port usage information is returned and **MaxPortsReported* is set to zero.
* If *ReportType* is CDB_REPORT_BYTES, the routine returns a byte array that specifies port number usage. Each byte in the returned information corresponds to a different port number. Using a zero-based index, byte zero at *Buffer* corresponds to COM1, byte 1 corresponds to COM2, and so on. A byte value of 1 indicates the port number is in use and a value of zero indicates the port number is not in use. The number of port numbers for which the routine returns usage information is the minimum of the current database size and *BufferSize*. The routine does not set **MaxPortsReported*. If *BufferSize* is zero, no port usage information is returned.

**ComDBGetCurrentPortUsage** runs in user mode.

## See also

[ComDBClaimNextFreePort](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclaimnextfreeport)

[ComDBClaimPort](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbclaimport)

[ComDBResizeDatabase](https://learn.microsoft.com/windows/desktop/api/msports/nf-msports-comdbresizedatabase)