## Description

The **AcxStreamInitAssignProperties** function assigns an array of properties to a stream using an *ACXSTREAM_INIT* object.

## Parameters

### `StreamInit`

Defined by an ACXSTREAM_INIT object, that is used to define the stream initialization. For more information about ACX Objects, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Properties`

An array of [ACX_PROPERTY_ITEM structures](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_property_item) that describe the requested property sets, properties and flags.

### `PropertiesCount`

A one based count of the number of Properties in the Properties array.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

### Example

Example usage is shown below.

```cpp

    ACX_PROPERTY_ITEM StreamProperties[] =
    {
        {
            &KSPROPSETID_DrmAudioStream,
            KSPROPERTY_DRMAUDIOSTREAM_CONTENTID,
            ACX_PROPERTY_ITEM_FLAG_SET,
            Codec_EvtStreamSetContentId,
            NULL,  // Reserved
            sizeof(KSP_DRMAUDIOSTREAM_CONTENTID) - sizeof(KSPROPERTY), // ControlCb
            sizeof(KSDRMAUDIOSTREAM_CONTENTID), // ValueCb
        },
    };

    ULONG StreamPropertiesCount = SIZEOF_ARRAY(StreamProperties);

    status = AcxStreamInitAssignProperties(StreamInit,
                                           StreamProperties,
                                           StreamPropertiesCount);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
- [ACX_PROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_property_item)