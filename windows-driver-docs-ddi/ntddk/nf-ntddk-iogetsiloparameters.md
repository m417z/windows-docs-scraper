# IoGetSiloParameters function

## Description

This routine indicates if a file is within a Container context.

## Parameters

### `FileObject` [in]

The file in question.

## Return value

If **null**, the file is not in a container context. Otherwise, a non-null value of type [IO_FOEXT_SILO_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_io_foext_silo_parameters) indicates that the file is within a Container context.