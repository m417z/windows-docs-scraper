# ClusterGroupSetControl function

## Description

Initiates an operation affecting a groupset.

The
operation performed depends on the [control code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-codes) passed to the
*dwControlCode* parameter.

## Parameters

### `hGroupSet` [in]

Handle to the groupset to be affected.

### `hHostNode` [in, optional]

If non-**NULL**, handle to the node to perform the operation represented by the control
code. If **NULL**, the [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) that owns the
groupset performs the operation. Specifying *hHostNode* is optional.

### `dwControlCode` [in]

A [Collection Control Code](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/collection-control-codes-) specifying
the operation to be performed. For the syntax associated with a control code, refer to
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture) and the following
topics.

* [CLUSCTL_GROUPSET_GET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-collection-get-common-properties)
* [CLUSCTL_GROUPSET_GET_GROUPS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-collection-get-groups)
* [CLUSCTL_GROUPSET_GET_PROVIDER_GROUPS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-collection-get-provider-groups)
* [CLUSCTL_GROUPSET_GET_PROVIDER_COLLECTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-collection-get-provider-collections)
* [CLUSCTL_GROUPSET_GET_RO_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-collection-get-ro-common-properties)
* [CLUSCTL_GROUPSET_SET_COMMON_PROPERTIES](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-collection-set-common-properties)
* [CLUSCTL_GROUP_GET_PROVIDER_GROUPS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-group-get-provider-groups)
* [CLUSCTL_GROUP_GET_PROVIDER_COLLECTIONS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-group-get-provider-collections)

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

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation was successful. If the operation required an output buffer, *lpBytesReturned* (if not **NULL** on input) points to the actual size of the data returned in the buffer. |
| **ERROR_MORE_DATA** | The output buffer pointed to by *lpOutBuffer* was not large enough to hold the data resulting from the operation. The *lpBytesReturned* parameter (if not **NULL** on input) points to the size required for the output buffer. Only operations requiring an output buffer return **ERROR_MORE_DATA**. If the *lpOutBuffer* parameter is **NULL** and the *nOutBufferSize* parameter is zero, then **ERROR_SUCCESS** may be returned, not **ERROR_MORE_DATA**. |
| **[System error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes)** | The operation was not successful. If the operation required an output buffer, the value specified by *lpBytesReturned* (if not **NULL** on input) is unreliable. |