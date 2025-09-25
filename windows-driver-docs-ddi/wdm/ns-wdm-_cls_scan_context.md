# _CLS_SCAN_CONTEXT structure

## Description

The **CLFS_SCAN_CONTEXT** structure holds context information to support a scan of the containers in a Common Log File System (CLFS) log. The client allocates this structure by calling [ClfsCreateScanContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfscreatescancontext). Then, the client passes the structure repeatedly to [ClfsScanLogContainers](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-clfsscanlogcontainers).

## Members

### `cidNode`

A [CLFS_NODE_ID](https://learn.microsoft.com/windows/win32/api/clfs/ns-clfs-clfs_node_id) structure that contains the scan context's node identity and type.

### `plfoLog`

A pointer to a [LOG_FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents a CLFS log.

### `cIndex`

The index of the current container.

### `cContainers`

The number of containers to scan in each call to **ClfsScanLogContainers**. This is the number of elements in the array pointed to by *pinfoContainer*.

### `cContainersReturned`

The number of containers actually scanned in a call to **ClfsScanLogContainers**.

### `eScanMode`

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| CLFS_SCAN_INIT | The scan is reinitialized and begins at the first container in the container list. |
| CLFS_SCAN_FORWARD | The next set of containers is scanned. |
| CLFS_SCAN_BACKWARD | The previous set of containers is scanned. |
| CLFS_SCAN_CLOSE | The scan is closed. No containers are scanned. |

### `pinfoContainer`

A pointer to an array of [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cls_container_information) structures. The *cContainers* parameter specifies the number of elements in this array.