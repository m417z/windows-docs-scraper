# IVssExpressWriter::Unregister

## Description

Causes VSS to delete the writer's metadata from the express writer metadata store.

## Parameters

### `writerId` [in]

The globally unique identifier (GUID) of the writer class.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **VSS_E_OBJECT_NOT_FOUND**<br><br>0x80042308L | The *writerId* parameter specified a writer that does not exist. |

## Remarks

Before using this method, the caller must have used the [CreateMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivssexpresswriter-createmetadata) method to create a writer metadata object.

## See also

[IVssExpressWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivssexpresswriter)