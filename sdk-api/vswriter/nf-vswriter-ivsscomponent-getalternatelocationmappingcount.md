# IVssComponent::GetAlternateLocationMappingCount

## Description

The
**GetAlternateLocationMappingCount** method returns the number of alternate location mappings used by a requester in restoring data. Either a writer or a requester can call this method.

## Parameters

### `pcMappings` [out]

The address of a caller-allocated variable that receives the number of alternate location mappings.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |

## Remarks

The count of alternate location mappings returned by
**GetAlternateLocationMappingCount** may be due to not only files in the current component but to files in any of its nonselectable subcomponents.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

The count returned by
**GetAlternateLocationMappingCount** refers to the number of alternate location mappings used in the course of restoring files.

The count is updated by calls to
[IVssBackupComponents::AddAlternativeLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addalternativelocationmapping).

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmapping)