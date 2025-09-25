## Description

The **AcxStreamBridgeRemoveStream** function removes the specified ACXSTREAM from the ACXSTREAMBRIDGE object . For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Bridge`

An ACXSTREAMBRIDGE object is used by a circuit to propagate stream creation, the stream's states transitions and DRM settings between the endpoint's circuit stream segments. This object is only used in a multi-circuit (audio composite) scenario.

### `Stream`

A handle to the ACXSTREAM Object to be removed from the ACXSTREAMBRIDGE.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This DDI can only be called from the driver's stream cleanup handler context. The caller invokes this DDI to manually dissociate an input ACXSTREAM from the specified ACXSTREAMBRIDGE object.

Drivers call AcxStreamBridgeRemoveStream in these scenarios:

(a) drivers want to manually remove the ACXSTREAM from the ACXSTREAMBRIDGE.

(b) drivers (and their h/w requirements) need for the upper level ACXSTREAMs i.e., the circuit streams closer to the streaming bridge pin, to take action before downlevel ACXSTREAMs.

(c) drivers need to take action before and after the downlevel ACXSTREAM goes away.

For a AcxStreamBridgeMux type, only one downlevel ACXSTREAM is created independently of the number of input ACXSTREAMs added to this bridge. This means that the output ACXSTREAM (which for the local circuit the stream is represented with an ACXTARGETSTREAM), is only created for the first ACXSTREAM added to the ACXSTREAMBRIDGE. Any additional input ACXSTREAMs just take a reference to this existing ACXTARGETSTREAM.

For a AcxStreamBridgeMux type, the output ACXTARGETSTREAM is removed when the last input ACXSTREAM is removed from the ACXSTREAMBRIDGE with AcxStreamBridgeRemoveStream.

### Example

Example usage is shown below.

```cpp
    status = AcxStreamBridgeAddStream(bridge, stream);

    // Get I/O target to send I/O to the target stream.
    targetStream = AcxStreamBridgeGetTargetStream(bridge, stream);

    // Target stream is closed if this was last input ACXSTREAM removed.
    status = AcxStreamBridgeRemoveStream(bridge, stream);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)