# ClusterResourceControl function

## Description

Initiates
an operation affecting a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The operation performed
depends on the [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) passed to the
*dwControlCode* parameter.

## Parameters

### `hResource` [in]

Handle to the resource to be affected.

### `hHostNode` [in, optional]

Optional handle to the node to perform the operation. If **NULL**, the node that owns
the resource identified by *hResource* performs the operation.

### `dwControlCode` [in]

A [resource control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-control-codes), enumerated by the
[CLUSCTL_RESOURCE_CODES](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clusctl_resource_codes) enumeration, specifying
the operation to be performed. For the syntax associated with a control code, refer to
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture) and the following
topics:

* [CLUSCTL_RESOURCE_UNKNOWN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-unknown)
* [CLUSCTL_RESOURCE_GET_CHARACTERISTICS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-characteristics)
* [CLUSCTL_RESOURCE_GET_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-flags)
* [CLUSCTL_RESOURCE_GET_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-class-info)
* [CLUSCTL_RESOURCE_GET_REQUIRED_DEPENDENCIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-required-dependencies)
* [CLUSCTL_RESOURCE_GET_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-name)
* [CLUSCTL_RESOURCE_GET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-id)
* [CLUSCTL_RESOURCE_GET_RESOURCE_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-resource-type)
* [CLUSCTL_RESOURCE_ENUM_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-enum-common-properties)
* [CLUSCTL_RESOURCE_GET_RO_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-ro-common-properties)
* [CLUSCTL_RESOURCE_GET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-common-properties)
* [CLUSCTL_RESOURCE_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-common-properties)
* [CLUSCTL_RESOURCE_VALIDATE_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-validate-common-properties)
* [CLUSCTL_RESOURCE_GET_COMMON_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-common-property-fmts)
* [CLUSCTL_RESOURCE_ENUM_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-enum-private-properties)
* [CLUSCTL_RESOURCE_GET_RO_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-ro-private-properties)
* [CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-private-properties)
* [CLUSCTL_RESOURCE_SET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-private-properties)
* [CLUSCTL_RESOURCE_VALIDATE_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-validate-private-properties)
* [CLUSCTL_RESOURCE_GET_PRIVATE_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-private-property-fmts)
* [CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-add-registry-checkpoint)
* [CLUSCTL_RESOURCE_DELETE_REGISTRY_CHECKPOINT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-delete-registry-checkpoint)
* [CLUSCTL_RESOURCE_GET_REGISTRY_CHECKPOINTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-registry-checkpoints)
* [CLUSCTL_RESOURCE_ADD_CRYPTO_CHECKPOINT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-add-crypto-checkpoint)
* [CLUSCTL_RESOURCE_DELETE_CRYPTO_CHECKPOINT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-delete-crypto-checkpoint)
* [CLUSCTL_RESOURCE_GET_CRYPTO_CHECKPOINTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-crypto-checkpoints)
* [CLUSCTL_RESOURCE_GET_LOADBAL_PROCESS_LIST](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-loadbal-process-list)
* [CLUSCTL_RESOURCE_GET_NETWORK_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-network-name)
* [CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-get-virtual-server-token)
* [CLUSCTL_RESOURCE_NETNAME_SET_PWD_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-set-pwd-info)
* [CLUSCTL_RESOURCE_NETNAME_DELETE_CO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-delete-co)
* [CLUSCTL_RESOURCE_NETNAME_VALIDATE_VCO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-validate-vco)
* [CLUSCTL_RESOURCE_NETNAME_RESET_VCO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-reset-vco)
* [CLUSCTL_RESOURCE_NETNAME_REGISTER_DNS_RECORDS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-register-dns-records)
* [CLUSCTL_RESOURCE_GET_DNS_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-get-dns-name)
* [CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info)
* [CLUSCTL_RESOURCE_STORAGE_IS_PATH_VALID](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-is-path-valid)
* [CLUSCTL_RESOURCE_QUERY_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-query-delete)
* [CLUSCTL_RESOURCE_UPGRADE_DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-upgrade-dll)
* [CLUSCTL_RESOURCE_IPADDRESS_RENEW_LEASE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-ipaddress-renew-lease)
* [CLUSCTL_RESOURCE_IPADDRESS_RELEASE_LEASE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-ipaddress-release-lease)
* [CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_64BIT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-add-registry-checkpoint-64bit)
* [CLUSCTL_RESOURCE_ADD_REGISTRY_CHECKPOINT_32BIT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-add-registry-checkpoint-32bit)
* [CLUSCTL_RESOURCE_QUERY_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-query-maintenance-mode)
* [CLUSCTL_RESOURCE_SET_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-maintenance-mode)
* [CLUSCTL_RESOURCE_STORAGE_SET_DRIVELETTER](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-set-driveletter)
* [CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info-ex)
* [CLUSCTL_RESOURCE_FILESERVER_SHARE_ADD](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fileserver-share-add)
* [CLUSCTL_RESOURCE_FILESERVER_SHARE_DEL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fileserver-share-del)
* [CLUSCTL_RESOURCE_FILESERVER_SHARE_MODIFY](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fileserver-share-modify)
* [CLUSCTL_RESOURCE_FILESERVER_SHARE_REPORT](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fileserver-share-report)
* [CLUSCTL_RESOURCE_STORAGE_GET_MOUNTPOINTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-mountpoints)
* [CLUSCTL_RESOURCE_STORAGE_CLUSTER_DISK](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-cluster-disk)
* [CLUSCTL_RESOURCE_STORAGE_GET_DIRTY](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-dirty)
* [CLUSCTL_RESOURCE_SET_CSV_MAINTENANCE_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-csv-maintenance-mode)
* [CLUSCTL_RESOURCE_ENABLE_SHARED_VOLUME_DIRECTIO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-enable-shared-volume-directio)
* [CLUSCTL_RESOURCE_DISABLE_SHARED_VOLUME_DIRECTIO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-disable-shared-volume-directio)
* [CLUSCTL_RESOURCE_SET_SHARED_VOLUME_BACKUP_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-shared-volume-backup-mode)
* [CLUSCTL_RESOURCE_DELETE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-delete)
* [CLUSCTL_RESOURCE_INSTALL_NODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-install-node)
* [CLUSCTL_RESOURCE_EVICT_NODE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-evict-node)
* [CLUSCTL_RESOURCE_ADD_DEPENDENCY](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-add-dependency)
* [CLUSCTL_RESOURCE_REMOVE_DEPENDENCY](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-remove-dependency)
* [CLUSCTL_RESOURCE_ADD_OWNER](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-add-owner)
* [CLUSCTL_RESOURCE_REMOVE_OWNER](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-remove-owner)
* [CLUSCTL_RESOURCE_SET_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-name)
* [CLUSCTL_RESOURCE_CLUSTER_NAME_CHANGED](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-cluster-name-changed)
* [CLUSCTL_RESOURCE_CLUSTER_VERSION_CHANGED](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-cluster-version-changed)
* [CLUSCTL_RESOURCE_FORCE_QUORUM](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-force-quorum)
* [CLUSCTL_RESOURCE_INITIALIZE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-initialize)
* [CLUSCTL_RESOURCE_STATE_CHANGE_REASON](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-state-change-reason)
* [CLUSCTL_RESOURCE_PROVIDER_STATE_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-provider-state-change)
* [CLUSCTL_RESOURCE_LEAVING_GROUP](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-leaving-group)
* [CLUSCTL_RESOURCE_JOINING_GROUP](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-joining-group)
* [CLUSCTL_RESOURCE_FSWITNESS_GET_EPOCH_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fswitness-get-epoch-info)
* [CLUSCTL_RESOURCE_FSWITNESS_SET_EPOCH_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fswitness-set-epoch-info)
* [CLUSCTL_RESOURCE_FSWITNESS_RELEASE_LOCK](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-fswitness-release-lock)
* [CLUSCTL_RESOURCE_NETNAME_CREDS_UPDATED](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-creds-updated)

### `lpInBuffer` [in, optional]

Pointer to an input buffer containing information needed for the operation, or **NULL**
if no information is needed.

### `cbInBufferSize` [in]

The allocated size (in bytes) of the input buffer.

### `lpOutBuffer` [out, optional]

Pointer to an output buffer to receive the data resulting from the operation, or
**NULL** if no data will be returned.

### `cbOutBufferSize` [in]

The allocated size (in bytes) of the output buffer.

### `lpBytesReturned` [out, optional]

Returns the actual size (in bytes) of the data resulting from the operation. If this information is not
needed, pass **NULL** for *lpBytesReturned*.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The operation was successful. If the operation required an output buffer, *lpBytesReturned* (if not **NULL** on input) points to the actual size of the data returned in the buffer. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The output buffer pointed to by *lpOutBuffer* was not large enough to hold the data resulting from the operation. The *lpBytesReturned* parameter (if not **NULL** on input) points to the size required for the output buffer. Only operations requiring an output buffer return **ERROR_MORE_DATA**. If the *lpOutBuffer* parameter is **NULL** and the *cbOutBufferSize* parameter is zero, then **ERROR_SUCCESS** may be returned, not **ERROR_MORE_DATA**. |
| **ERROR_RESOURCE_PROPERTIES_STORED**<br><br>5024 (0x13A0) | Applies only to [CLUSCTL_RESOURCE_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-common-properties) and [CLUSCTL_RESOURCE_SET_PRIVATE_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-set-private-properties). Indicates that the properties were successfully stored but have not yet been applied to the resource. The new properties will take effect after the resource is taken offline and brought online again. |
| **ERROR_HOST_NODE_NOT_RESOURCE_OWNER**<br><br>5015 (0x1397) | The node specified by the *hNode* parameter is not the node that owns the resource specified by *hResource*. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was not successful. If the operation required an output buffer, the value specified by *lpBytesReturned* (if not **NULL** on input) is unreliable. |

## Remarks

When **ClusterResourceControl** returns
**ERROR_MORE_DATA**, set *cbOutBufferSize* to the number of bytes
pointed to by *lpBytesReturned*, and call the function again.

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[LPC and RPC Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/lpc-and-rpc-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

The **ClusterResourceControl** function is one
of the [control code functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-functions). For more information
on control codes and control code functions, see
[Using Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-control-codes).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[Resource Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-control-codes)