## Description

The **AcxStreamInitAssignMethods** function assigns an array of methods to a stream using the *ACXSTREAM_INIT* object.

## Parameters

### `StreamInit`

Defined by a ACXSTREAM_INIT object, that is used to define the stream initialization. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Methods`

An array of ACX_METHOD_ITEM that describes the methods to be assigned.

### `MethodsCount`

A one based count of the number of methods in the Methods array.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp
    static ACX_METHOD_ITEM StreamMethods[] =
    {
        {
            &KSMETHODSETID_AcxTestMethod,
            KSMETHOD_ACXSTREAM_TEST_IN2OUT,
            ACX_METHOD_ITEM_FLAG_SEND,
            Codec_EvtTestIn2OutMethodCallback,
            NULL,               // Reserved
            sizeof(ULONG),      // ControlCb
            sizeof(ULONG),      // ValueCb
        },
    };

    static ULONG StreamMethodsCount = SIZEOF_ARRAY(StreamMethods);

    status = AcxStreamInitAssignMethods(StreamInit,
                                         StreamMethods,
                                         StreamMethodsCount);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)