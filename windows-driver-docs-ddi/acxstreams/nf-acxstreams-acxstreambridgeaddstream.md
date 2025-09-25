## Description

The **AcxStreamBridgeAddStream** function adds an existing ACXSTREAM to an existing ACXSTREAMBRIDGE. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Parameters

### `Bridge`

An *ACXSTREAMBRIDGE* object is used by a circuit to propagate stream creation, the stream's states transitions and DRM settings between the endpoint's circuit stream segments. This object is only used in a multi-circuit (audio composite) scenario.

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Drivers call AcxStreamBridgeAddStream in these scenarios:

(a) drivers want to manually select the ACXSTREAMBRIDGE to use for the current ACXSTREAM.

(b) drivers (and their hardware requirements) have a need for the downlevel ACXCIRCUITs, i.e., the circuits closer to the device bridge pin, to take action before upper level ACXCIRCUITs take action.

(c) drivers need to take action before and after the downlevel ACXCIRCUITs.

For a AcxStreamBridgeMux type, only one downlevel ACXSTREAM is created independently of the number of input ACXSTREAMs added to this bridge. This means that the output ACXSTREAM (which for the local circuit the stream is represented with an ACXTARGETSTREAM), is only created for the first ACXSTREAM added to the ACXSTREAMBRIDGE. Any additional input ACXSTREAMs, just take a reference to this existing ACXTARGETSTREAM.

For a AcxSTreamBridgeMux type, the output ACXTARGETSTREAM is removed when the last input ACXSTREAM is removed from the ACXSTREAMBRIDGE with AcxStreamBridgeRemoveStream.

### Example

Example usage is shown below. Error handling code is not shown.

```cpp
        status = AcxStreamBridgeCreate(Circuit, &attributes, &bridgeCfg, &bridge);

        // Pin ID 1 is the bridge pin in this example.
        bridgePin = AcxCircuitGetPinById(Circuit, 1);

        status = AcxPinAddStreamBridges(bridgePin, &bridge, 1);

        status = AcxStreamBridgeAddStream(bridge, stream);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)