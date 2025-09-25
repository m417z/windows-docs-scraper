## Description

The **AcxCircuitAddElements** function adds elements to an ACXCIRCUIT.

## Parameters

### `Circuit`

An existing ACXCIRCUIT object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Elements`

One or more ACXELEMENT objects that will be added to the circuit.

### `ElementsCount`

The number of elements that will be added to the circuit. This is a one based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

The driver can only add elements to a circuit before the circuit is added to the device.
The driver cannot change the circuit's elements at run time.

### Example

Example usage is shown below.

```cpp

    //
    // Add a second element.
    //
    ACX_ELEMENT_CONFIG_INIT(&elementCfg);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_ELEMENT_CONTEXT);
    attributes.ParentObject = circuit;

    status = AcxElementCreate(circuit, &attributes, &elementCfg, &elements[1]);

    //
    // Add the elements to the circuit.
    //
    status = AcxCircuitAddElements(circuit, elements, SIZEOF_ARRAY(elements));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)