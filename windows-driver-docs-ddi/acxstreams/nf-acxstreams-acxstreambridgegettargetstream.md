## Description

The **AcxStreamBridgeGetTargetStream** function gets the ACXTARGETSTREAM object associated with the input ACXSTREAM object on the specified ACXSTREAMBRIDGE object. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Bridge`

An ACXSTREAMBRIDGE object handle.

### `Stream`

An ACXSTREAM object handle. An ACXSTREAM object represents an audio stream created by a circuit.

## Return value

An ACXTARGETSTREAM object handle.

## Remarks

An ACXSTREAMBRIDGE object is used by a circuit to propagate stream creation, the stream's states transitions and DRM settings between the endpoint's circuit stream segments. This object is only used in a multi-circuit (audio composite) scenario.

This DDI can only be called from the driver's input stream property handler context. The caller invokes this DDI to manually send I/O to the out-stream of this stream-bridge object.

The returned target stream is only valid in the context of the input stream property handler. Note that the target stream may be already busy sending other I/O (such as state change) as directed by other ks property stream operations.

### Example

Example usage is shown below.

```cpp
    status = AcxStreamBridgeAddStream(bridge, stream);

    targetStream = AcxStreamBridgeGetTargetStream(bridge, stream);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)