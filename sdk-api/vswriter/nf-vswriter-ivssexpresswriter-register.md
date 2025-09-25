# IVssExpressWriter::Register

## Description

Causes VSS to store the writer's metadata in the express writer metadata store.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **VSS_E_OBJECT_ALREADY_EXISTS**<br><br>0x8004230DL | Metadata has already been stored for this writer. |

## Remarks

Before using this method, the caller must have either used the [LoadMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivssexpresswriter-loadmetadata) method to load the writer's metadata directly or used the [CreateMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivssexpresswriter-createmetadata) method to create a writer metadata object.

## See also

[IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter)