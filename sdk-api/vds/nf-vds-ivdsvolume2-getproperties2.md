# IVdsVolume2::GetProperties2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Returns
property information for the current volume. This method is identical to the [IVdsVolume::GetProperties](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolume-getproperties) method, except that it returns a [VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2) structure instead of a [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure.

## Parameters

### `pVolumeProperties` [out]

The address of the [VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop) structure
allocated and passed in by the caller. VDS allocates memory for the **pwszName** member
string. Callers must free the string by using the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| ****VDS_S_PROPERTIES_INCOMPLETE****<br><br>0x00042715L | Some but not all of the properties were successfully retrieved. Note that there are many possible reasons for failing to retrieve all properties, including device removal. |

## Remarks

This method retrieves the unique volume identifier for a volume. The structure that contains that identifier is [VDS_VOLUME_PROP2](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop2), not [VDS_VOLUME_PROP](https://learn.microsoft.com/windows/desktop/api/vds/ns-vds-vds_volume_prop).

Note that a unique volume identifier is not the same as a volume GUID path. To find the volume GUID paths for a volume, use the [IVdsVolumeMF3::QueryVolumeGuidPathnames](https://learn.microsoft.com/windows/desktop/api/vds/nf-vds-ivdsvolumemf3-queryvolumeguidpathnames) method.

## See also

[IVdsVolume2](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsvolume2)