# VSS_DIFF_AREA_PROP structure

## Description

The **VSS_DIFF_AREA_PROP** structure
describes associations between volumes containing the original file data and volumes containing the
shadow copy storage area (also known as the diff area).

## Members

### `m_pwszVolumeName`

The original volume name.

### `m_pwszDiffAreaVolumeName`

The shadow copy storage area volume name.

### `m_llMaximumDiffSpace`

Maximum space used on the shadow copy storage area volume for this association.

### `m_llAllocatedDiffSpace`

Allocated space on the shadow copy storage area volume by this association. This must be less than or equal
to *m_llMaximumDiffSpace*.

### `m_llUsedDiffSpace`

Used space from the allocated area above. This must be less than or equal
to *m_llAllocatedDiffSpace*.

## Remarks

The **m_llMaximumDiffSpace** member is passed as a parameter to the [IVssDifferentialSoftwareSnapshotMgmt::AddDiffArea](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-adddiffarea), [IVssDifferentialSoftwareSnapshotMgmt::ChangeDiffAreaMaximumSize](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt-changediffareamaximumsize), and [IVssDifferentialSoftwareSnapshotMgmt2::ChangeDiffAreaMaximumSizeEx](https://learn.microsoft.com/windows/desktop/api/vsmgmt/nf-vsmgmt-ivssdifferentialsoftwaresnapshotmgmt2-changediffareamaximumsizeex) methods.

## See also

[VSS_MGMT_OBJECT_UNION](https://learn.microsoft.com/openspecs/windows_protocols/ms-scmp/63b53947-2649-4eac-a883-498f77361396)

[Volume Shadow Copy API Structures](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-structures)