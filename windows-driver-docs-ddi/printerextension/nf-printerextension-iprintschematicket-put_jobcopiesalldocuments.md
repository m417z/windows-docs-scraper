## Description

Sets the copy count.

This property is write-only.

## Parameters

### `ulJobCopiesAllDocuments`

Defines the **ULONG** parameter *ulJobCopiesAllDocuments*.

## Return value

Returns an **HRESULT** value. If the property call was not successful, it returns the appropriate **HRESULT** error code.

## Remarks

Be aware of the fact that the [IPrintSchemaTicket::GetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschematicket-getcapabilities) method retrieves a new PrintCapabilities document, which it also caches every time it is invoked. This means that if you use **IPrintSchemaTicket::put_JobCopiesAllDocuments** or [IPrintSchemaFeature::SelectedOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemafeature-put_selectedoption) on PrintTicket, the cached PrintCapabilities document gets corrupted or modified and the cache will be purged.

## See also

[IPrintSchemaFeature::SelectedOption](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschemafeature-put_selectedoption)

[IPrintSchemaTicket](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nn-printerextension-iprintschematicket)

[IPrintSchemaTicket::GetCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/printerextension/nf-printerextension-iprintschematicket-getcapabilities)