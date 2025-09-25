# IVdsHwProviderStoragePools::CreateLunInStoragePool

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a LUN in a [storage pool](https://learn.microsoft.com/windows/desktop/VDS/storage-pool-object).

## Parameters

### `type` [in]

A [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type) enumeration value that specifies the type of LUN to be created. The new
LUN can be an automagic type or a specific RAID type, but not both. If the caller specifies an automagic type, one or more automagic hints should be specified in the *pHints2* parameter.

The interface pointer for the new
[LUN object](https://learn.microsoft.com/windows/desktop/VDS/lun-object) can be retrieved by calling the
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method on the interface pointer returned in the
*ppAsync* parameter. The
[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure returned by **Wait** contains the
LUN object interface pointer in the **cl.pLunUnk** member.

### `ullSizeInBytes` [in]

The size, in bytes, of the new LUN. The provider can round the size up or down to meet alignment
requirements or other restrictions. (In most cases, the provider rounds up, ensuring that, with rare
exceptions, the LUN is at least as large as requested.)

After the LUN is created, the caller can determine the actual size of the LUN by calling the
[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) method.

### `StoragePoolId` [in]

A [VDS_OBJECT_ID](https://learn.microsoft.com/windows/desktop/VDS/vds-data-types) value that identifies the storage pool where the LUN is to be created. This parameter is required and cannot be GUID_NULL.

### `pwszUnmaskingList` [in]

A list specifying the computers to be granted access the LUN. The list is a
semicolon-delimited, **NULL**-terminated, human-readable string.

 If the value is "*", all computers that have an HBA port attached to the storage subsystem are to be granted access to the LUN. If the value is "", no computers are to be granted access to the LUN.

**Note** In practice, if the value is "*", most hardware providers only grant the ports and initiators on the local computer access to the LUN.

If "*" or "" is specified, no other value can be specified.

For Fibre Channel networks and serial attached SCSI (SAS) networks, each entry is a 64-bit World-Wide Name (WWN) of each port to which the LUN is unmasked,
formatted as a hexadecimal string (16 characters long), most significant byte first. For
example, a WWN address of 01:23:45:67:89:AB:CD:EF is represented as "0123456789ABCDEF". For more information, see the T10 specifications for [Fibre Channel](https://t10.org/drafts.htm#FibreChannel) and [SAS](https://t10.org/drafts.htm#SCSI3_SAS).

For iSCSI networks, each entry is an iSCSI-qualified name (IQN) of each initiator to which the LUN is unmasked. A LUN unmasked
to a particular initiator is considered to be associated with that initiator.

**Note** The unmasking list can contain the same WWN or IQN more than once. The caller is not expected to remove
duplicates from the list or to validate the format of the WWN or IQN.

After the LUN is created, the caller can determine the actual unmasking list by calling the
[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) method.

### `pHints2` [in]

A pointer to a [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure that specifies the hints to be used in creating the LUN. The provider is not required to apply the hints to the LUN. The hints specified in the **VDS_HINTS2** structure are only a request to the provider.

After the LUN is created, the caller can determine the hints that the provider applied by calling the
[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2) method.

If the *type* parameter specifies a non-automagic type, this parameter should be **NULL**.

### `ppAsync` [out]

A pointer to an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface that upon successful completion receives the **IVdsAsync** interface to monitor and control this operation. Callers must release the interface received when they are done with it. If the [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) method is called on the interface and a success HRESULT value is returned, the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output) structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## Remarks

By choosing appropriate values for the *type* and *pHints2* parameters, the caller can specify the attributes of the LUN wholly, partially, or minimally. The provider can
automatically include unspecified attributes, based on the automagic hints specified in the
[VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure that the *pHints2* parameter points to.

**Notes to implementers:** The provider must return an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer in the *ppAsync* parameter, even if the call to this method does not initiate an asynchronous operation.

The list of WWNs and IQNs in the *pwszUnmaskingList* parameter may contain duplicate names. It is the provider's responsibility to validate all names in the list and remove duplicates if necessary.

In response to the **CreateLunInStoragePool** method and
before unmasking the new LUN to any host, the provider should fill the first and last megabytes with zeros,
leaving the LUN uninitialized.

There is a subtle difference between the **E_INVALIDARG** and
**VDS_E_NOT_SUPPORTED** return values. Providers are not expected to implement every feature that the VDS
API can present to a client. For example, the
**CreateLunInStoragePool** method exposes the ability to
create many different types of LUNs (for example, simple, mirror, striped, and parity). However, providers are not required to support all
types of LUNs. If the caller specifies a value for the *type* parameter that is not a valid [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type) enumeration value, the provider should return **E_INVALIDARG**. If the caller specifies a valid *type* value that the provider does not support, the provider should return VDS_E_NOT_SUPPORTED.

## See also

[IVdsHwProviderStoragePools](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdshwproviderstoragepools)

[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2)

[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties)

[VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2)

[VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type)