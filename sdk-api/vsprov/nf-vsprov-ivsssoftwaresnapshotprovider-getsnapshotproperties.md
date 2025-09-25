# IVssSoftwareSnapshotProvider::GetSnapshotProperties

## Description

Gets the properties of the specified shadow copy.

## Parameters

### `SnapshotId` [in]

Shadow copy identifier.

### `pProp` [out]

The address of a caller-allocated [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure that receives the shadow copy properties. The provider is responsible for setting the members of this structure. All members are required except **m_pwszExposedName** and **m_pwszExposedPath**, which the provider can set to **NULL**. The provider allocates memory for all string members that it sets in the structure. When the structure is no longer needed, the caller is responsible for freeing these strings by calling the [VssFreeSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-vssfreesnapshotproperties) function.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The requested information was successfully returned. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified volume was not found. |
| **VSS_E_PROVIDER_VETO** | Provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller should set the contents of the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure to zero before calling the **GetSnapshotProperties** method.

The provider is responsible for allocating and freeing the strings in the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure.

## See also

[IVssSoftwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsssoftwaresnapshotprovider)

[VssFreeSnapshotProperties](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-vssfreesnapshotproperties)