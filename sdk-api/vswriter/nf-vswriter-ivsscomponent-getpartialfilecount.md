# IVssComponent::GetPartialFileCount

## Description

The
**GetPartialFileCount** method returns the number of partial files associated with a component.

## Parameters

### `pcPartialFiles` [out]

The address of a caller-allocated variable that receives the number of partial files.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## See also

[IVssBackupComponents::SetRangesFilePath](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setrangesfilepath)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)

[IVssComponent::GetPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfile)