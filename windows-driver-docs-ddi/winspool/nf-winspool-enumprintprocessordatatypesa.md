# EnumPrintProcessorDatatypesA function

## Description

A print processor's **EnumPrintProcessorDatatypes** function enumerates the data types that the print processor supports.

## Parameters

### `pName` [in, optional]

Caller-supplied pointer to a string representing name of the server on which the print processor is installed. If **NULL**, the server is the local system.

### `pPrintProcessorName` [in]

Caller-supplied pointer to a string representing the print processor name.

### `Level`

Caller-supplied value indicating the type of the structures to be returned in the buffer pointed to by *pDatatypes*. This value must be 1, indicating that the structure is DATATYPES_INFO_1.

### `pDatatypes` [out, optional]

Caller-supplied pointer to a buffer to receive an array of DATATYPES_INFO_1 structures, followed by a set of character strings representing data type names. The DATATYPES_INFO_1 structure is described in the Microsoft Windows SDK documentation. The structure member *pName* must be of type LPWSTR.

### `cbBuf`

Caller-supplied value representing the size, in bytes, of the buffer pointed to by *pDatatypes*.

### `pcbNeeded` [out]

Caller-supplied pointer to a location to receive the minimum required size for the buffer pointed to by *pDatatypes*.

### `pcReturned` [out]

Caller-supplied pointer to a location to receive the number of DATATYPES_INFO_1 structures returned in the buffer pointed to by *pDatatypes*.

## Return value

If the operation succeeds, the function should return **TRUE**. If the operation fails, the function should call **SetLastError** to set an error code, and then return **FALSE**.

## Remarks

Print processors are required to export an **EnumPrintProcessorDatatypes** function. The local print provider calls the function during initialization. The function is also called when an application calls the spooler's version of the same function.

The function must return an array of DATATYPES_INFO_1 structures, with each structure pointing to a string that represents a data type. The actual strings must also be included in the buffer, after the structure array. See [Sample Print Processor](https://learn.microsoft.com/windows-hardware/drivers/print/sample-print-processor) for an example.

The function should return the number of DATATYPES_INFO_1 structures returned (that is, the number of data types supported) in the location pointed to by *pcReturned*.

The function should return the minimum required buffer size in the location pointed to by *pcbNeeded*. If the supplied buffer is too small, the function should specify a value for *pcbNeeded*, set the error code to ERROR_INSUFFICIENT_BUFFER, and return **FALSE**.