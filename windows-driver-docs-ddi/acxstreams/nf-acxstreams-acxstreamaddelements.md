## Description

**AcxStreamAddElements** is used to add stream elements to an AcxStream.

## Parameters

### `Stream`

An existing *ACXSTREAM* Object. An ACXSTREAM object represents an audio stream created by a circuit. The stream can include zero or more elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Elements`

A pointer to an array of one or more existing *ACXELEMENT* Objects.

### `ElementsCount`

The count of elements to be added. This is a 1 based count.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp

    ACX_ELEMENT_CONFIG_INIT(&elementCfg);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, ELEMENT_CONTEXT);

    attributes.ParentObject = stream;
    status = AcxElementCreate(stream, &attributes, &elementCfg, &elements[0]);
    elementCtx = GetElementContext(elements[0]);

    ACX_ELEMENT_CONFIG_INIT(&elementCfg);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, ELEMENT_CONTEXT);

    attributes.ParentObject = stream;
    status = AcxElementCreate(stream, &attributes, &elementCfg, &elements[1]);
    elementCtx = GetElementContext(elements[1]);
    //
    // Add stream elements
    //
    status = AcxStreamAddElements(stream, elements, SIZEOF_ARRAY(elements));
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)