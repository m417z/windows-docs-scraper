## Description

The **EVT_ACX_STREAM_ASSIGN_DRM_CONTENT_ID** event tells the driver to assign a content ID for the purposes of DRM streaming.

## Parameters

### `Stream`

An existing ACXSTREAM Object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ContentId`

Specifies a nonzero DRM content ID assigned to an ACX audio stream by [AcxDrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxdrmcreatecontentmixed). Note that a content ID of zero represents an audio stream with default DRM content rights, and cannot be used with this function.

### `DrmRights`

Specifies the DRM content rights that are assigned to the stream that is identified by ContentId. This parameter is a pointer to a [ACXDRMRIGHTS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acxdrmrights).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    //
    // Init streaming callbacks.
    //
    ACX_STREAM_CALLBACKS_INIT(&streamCallbacks);
    ...
    streamCallbacks.EvtAcxStreamAssignDrmContentId = EvtStreamAssignDrmContentId;

    status = AcxStreamInitAssignAcxStreamCallbacks(StreamInit, &streamCallbacks);

...

_Use_decl_annotations_
PAGED_CODE_SEG
NTSTATUS
EvtStreamAssignDrmContentId(
    _In_ ACXSTREAM      Stream,
    _In_ ULONG          DrmContentId,
    _In_ PACXDRMRIGHTS  DrmRights
    )
{
    PSTREAM_CONTEXT ctx;

    PAGED_CODE();

    ctx = GetStreamContext(Stream);
    ASSERT(ctx);
    ASSERT(ctx->StreamEngine);

    return ctx->StreamEngine->AssignDrmContentId(DrmContentId, DrmRights);
}

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [ACXDRMRIGHTS structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acxdrmrights)
- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)