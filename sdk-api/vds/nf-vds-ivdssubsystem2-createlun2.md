# IVdsSubSystem2::CreateLun2

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Creates a LUN. This method is identical to the [IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun) method, except that automagic hints are provided using a [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure instead of a [VDS_HINTS](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints) structure.

## Parameters

### `type` [in]

A [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type) enumeration value that specifies the LUN type. The new
LUN can be an automagic type or a specific RAID type, but not both. If the caller specifies an automagic type, one or more automagic hints should be specified in the *pHints* parameter.

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

### `pDriveIdArray` [in]

A pointer to an array that contains a [VDS_OBJECT_ID](https://learn.microsoft.com/windows/desktop/VDS/vds-data-types) for each of the drives to be used to create the LUN. By specifying a non-**NULL** value for this parameter, the caller is requesting that the provider use all of the drives, in the order provided, using all of the extents on one drive before moving on to the
next, and stopping when the LUN has reached the requested size.

Alternatively, the caller can direct the provider to select the drives automatically by passing
**NULL** in this parameter and 0 in *lNumberOfDrives*. (Pass
**NULL** if and only if *lNumberOfDrives* is 0.)

If the *type* parameter specifies an automagic type, this parameter should be **NULL**.

### `lNumberOfDrives` [in]

The number of drives specified in *pDriveIdArray*. If the caller passes 0, the
provider selects the drives.

If the *type* parameter specifies an automagic type, this parameter should be 0.

After the LUN is created, the caller can determine which drives are in use by calling the
[IVdsLunPlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryextents) method.

### `pwszUnmaskingList` [in]

A list specifying the computers to be granted access the LUN. The list is a
semicolon-delimited, **NULL**-terminated, human-readable string.

If the value is "*", all computers that have an HBA port attached to the storage subsystem are to be granted access to the LUN. If the value is "", no computers are to be granted access to the LUN.

**Note** In practice, if the value is "*", most hardware providers only grant the ports and initiators on the local computer access to the LUN.

If "*" or "" is specified, no other value can be specified.

For Fibre Channel networks and serial attached SCSI (SAS) networks, each entry is a 64-bit World-Wide Name (WWN) of each port to which the LUN is unmasked,
formatted as a hexadecimal string (16 characters long), most significant byte first. For
example, a WWN address of 01:23:45:67:89:AB:CD:EF is represented as "0123456789ABCDEF". For more information, see the T10 specifications for [Fibre Channel](https://t10.org/drafts.htm#FibreChannel) and [SAS](https://t10.org/drafts.htm#SCSI3_SAS).

For iSCSI networks, each entry is an iSCSI qualified name (IQN) of each initiator to which the LUN is unmasked. A LUN unmasked
to a particular initiator is considered to be associated with that initiator.

**Note** The unmasking list can contain the same WWN or IQN more than once. The caller is not expected to remove
duplicates from the list or to validate the format of the WWN or IQN.

After the LUN is created, the caller can determine the actual unmasking list by calling the
[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties) method.

### `pHints2` [in]

Pointer to a [VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure that specifies the hints to be used in creating the LUN. The provider is not required to apply the hints to the LUN. The hints specified in the **VDS_HINTS2** structure are only a request to the provider.

After the LUN is created, the caller can determine the hints that the provider applied by calling the
[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2) method.

If the *type* parameter specifies a non-automagic type, this parameter should be **NULL**.

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer,
which VDS initializes on return. Callers must release the interface. Use this interface to cancel, wait for, or
query the status of the operation.

If [IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) is called on the returned interface pointer and a success HRESULT value is returned,
the interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)
structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **VDS_E_PROVIDER_CACHE_CORRUPT**<br><br>0x8004241FL | There is a software or communication problem inside a provider that caches information about the array. Use the [IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate) method followed by the [IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh) method to restore the cache. |
| **VDS_E_OBJECT_DELETED**<br><br>0x8004240BL | The subsystem object is no longer present. |
| **VDS_E_OBJECT_STATUS_FAILED**<br><br>0x80042431L | The subsystem is in a failed state and is unable to perform the requested operation. |
| **VDS_E_ANOTHER_CALL_IN_PROGRESS**<br><br>0x80042404L | Another operation is in progress; this operation cannot proceed until the previous operation or operations are complete. |
| **VDS_E_OBJECT_NOT_FOUND**<br><br>0x80042405L | The identifier does not refer to an existing object. This value can be returned from any method that takes a **VDS_OBJECT_ID** constant. |
| **VDS_E_NOT_SUPPORTED**<br><br>0x80042400L | This operation or combination of parameters is not supported by this provider. |
| **VDS_E_NOT_ENOUGH_SPACE**<br><br>0x8004240FL | There is not enough usable space for this operation. |
| **VDS_E_NOT_ENOUGH_DRIVE**<br><br>0x80042410L | Too few free drives are present in the subsystem to complete this operation. |

## Remarks

By choosing appropriate values for the *type* and *pHints2* parameters, the caller can specify the attributes of the LUN wholly, partially, or minimally. The provider can
automatically include unspecified attributes, based on the automagic hints specified in the
[VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2) structure that the *pHints* parameter points to.

**Notes to implementers:** The provider must return an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer in the *ppAsync* parameter, even if the call to this method does not initiate an asynchronous operation.

The list of WWNs and IQNs in the *pwszUnmaskingList* parameter may contain duplicate names. It is the provider's responsibility to validate all names in the list and remove duplicates if necessary.

In response to the **CreateLun2** method and
before unmasking the new LUN to any host, the provider should fill the first and last megabytes with zeros,
leaving the LUN uninitialized.

There is a subtle difference between the **E_INVALIDARG** and
**VDS_E_NOT_SUPPORTED** return values. Providers are not expected to implement every feature that the VDS
API can present to a client. For example, the
**CreateLun2** method exposes the ability to
create many different types of LUNs (for example, simple, mirror, striped, and parity). However, providers are not required to support all
types of LUNs. If the caller specifies a value for the *type* parameter that is not a valid [VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type) enumeration value, the provider should return **E_INVALIDARG**. If the caller specifies a valid *type* value that the provider does not support, the provider should return VDS_E_NOT_SUPPORTED.

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait)

[IVdsHwProvider::Reenumerate](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-reenumerate)

[IVdsHwProvider::Refresh](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdshwprovider-refresh)

[IVdsLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdslun)

[IVdsLun2::QueryHints2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun2-queryhints2)

[IVdsLun::GetProperties](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslun-getproperties)

[IVdsLunPlex::QueryExtents](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdslunplex-queryextents)

[IVdsSubSystem2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdssubsystem2)

[IVdsSubSystem::CreateLun](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-createlun)

[IVdsSubSystem::QueryLuns](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdssubsystem-queryluns)

[VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)

[VDS_HINTS2](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_hints2)

[VDS_LUN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_lun_type)