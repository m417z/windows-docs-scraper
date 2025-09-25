## Description

Gets the print job identifier (ID).

This property is read-only.

## Parameters

### `pulID`

Defines the **ULONG** parameter *pulID*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

You must not use the **IPrintJob::Id** property to invoke spooler Job APIs. This property is only provided as a way for you to identify a particular job, and to help with ordering or sorting of the jobs in the job snapshot.

## See also

[IPrintJob](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintjob)