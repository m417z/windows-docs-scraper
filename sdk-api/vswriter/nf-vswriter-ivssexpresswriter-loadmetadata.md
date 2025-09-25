# IVssExpressWriter::LoadMetadata

## Description

Causes VSS to load the writer's metadata from a string instead of the express writer metadata store.

## Parameters

### `metadata` [in]

A null-terminated wide character string that contains the writer's metadata.

### `reserved` [in]

This parameter is reserved for system use.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **VSS_E_INVALID_XML_DOCUMENT**<br><br>0x80042311L | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## See also

[IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter)