# IVdsIscsiInitiatorAdapter::LoginToTarget

## Description

[Beginning with Windows 8 and Windows Server 2012, the [Virtual Disk Service](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-portal) COM interface is superseded by the [Windows Storage Management API](https://learn.microsoft.com/windows-hardware/drivers/storage/windows-storage-management-api-portal).]

Performs a manual login to an iSCSI target.

## Parameters

### `loginType` [in]

The type of login that will be performed, enumerated by
[VDS_ISCSI_LOGIN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_login_type).

### `targetId` [in]

The **VDS_OBJECT_ID** of the target to login to. **GUID_NULL**
indicates that the initiator is to select the portal.

### `targetPortalId` [in]

The **VDS_OBJECT_ID** of the target portal by which the login operation is performed.
**GUID_NULL** indicates that the initiator is to select the portal.

### `initiatorPortalId` [in]

The **VDS_OBJECT_ID** of the initiator portal by which the login operation is
performed.

### `ulLoginFlags` [in]

Flags enumerated by [VDS_ISCSI_LOGIN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_login_flag)
specifying login options.

### `bHeaderDigest` [in]

If **TRUE**, the initiator should enable header digest when logging into the target portal.

### `bDataDigest` [in]

If **TRUE**, the initiator should enable data digest when logging into the target portal.

### `authType` [in]

The type of authentication required to log into the target, enumerated by
[VDS_ISCSI_AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_auth_type).

### `ppAsync` [out]

The address of an [IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync) interface pointer. VDS
initializes the interface on return. Callers must release the interface. Use this interface to cancel, wait
for, or query the status of the operation. If
[IVdsAsync::Wait](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nf-vdshwprv-ivdsasync-wait) is called on this interface and a success HRESULT value is returned, the
interfaces returned in the [VDS_ASYNC_OUTPUT](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ns-vdshwprv-vds_async_output)
structure must be released by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on each interface pointer. However, if **Wait** returns a failure HRESULT value, or if the *pHrResult* parameter of **Wait** receives a failure HRESULT value, the interface pointers in the **VDS_ASYNC_OUTPUT** structure are **NULL** and do not need to be released. You can test for success or failure HRESULT values by using the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) and [FAILED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-failed) macros defined in Winerror.h.

## Return value

This method can return standard HRESULT values, such as E_INVALIDARG or E_OUTOFMEMORY, and [VDS-specific return values](https://learn.microsoft.com/windows/desktop/VDS/virtual-disk-service-common-return-codes). It can also return converted [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) using the [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) macro. Errors can originate from VDS itself or from the underlying [VDS provider](https://learn.microsoft.com/windows/desktop/VDS/about-vds) that is being used. Possible return values include the following.

| Return code/value | Description |
| --- | --- |
| **S_OK** | The login was successfully completed. |
| **VDS_E_ISCSI_LOGIN_FAILED**<br><br>0x80042708L | Another operation is in progress. This operation cannot proceed until the previous operations are complete. |

## See also

[IVdsAsync](https://learn.microsoft.com/windows/desktop/api/vdshwprv/nn-vdshwprv-ivdsasync)

[IVdsIscsiInitiatorAdapter](https://learn.microsoft.com/windows/desktop/api/vds/nn-vds-ivdsiscsiinitiatoradapter)

[VDS_ISCSI_AUTH_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_auth_type)

[VDS_ISCSI_LOGIN_FLAG](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_login_flag)

[VDS_ISCSI_LOGIN_TYPE](https://learn.microsoft.com/windows/desktop/api/vdshwprv/ne-vdshwprv-vds_iscsi_login_type)