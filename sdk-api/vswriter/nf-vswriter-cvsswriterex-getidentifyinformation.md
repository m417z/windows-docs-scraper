# CVssWriterEx::GetIdentifyInformation

## Description

Obtains the metadata that the writer's [OnIdentify](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onidentify) or [OnIdentifyEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex-onidentifyex) method previously reported.

**GetIdentifyInformation** is a protected method that is implemented by the
[CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex) base class.

## Parameters

### `ppMetadata` [out]

A doubly indirect pointer to an
[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object that contains the returned metadata. Writers must not set the returned pointer to **NULL** or call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on it, because the VSS service holds a reference to the object.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata) object. |
| **E_FAIL** | There was an internal error in the writer. |

## Remarks

The **GetIdentifyInformation** method can only be called in a writer's [OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup), [OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot), or [OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot) method.

## See also

[CVssWriterEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriterex)