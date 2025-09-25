## Description

The **ACX_ELEMENT_CONFIG** structure is used to define the acx element configuration.

## Members

### `Size`

The length, in bytes, of this structure.

### `Id`

A number that represents the element ID.

### `Type`

The KSNODETYPE, for example KSNODETYPE_AUDIO_ENGINE or KSNODETYPE_AUDIO_KEYWORDDETECTOR. For more information, see [Audio Topology Nodes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-topology-nodes).

### `Name`

A pointer to a GUID that represents the name of the element. Can be used for debugging and will default to GUID_NULL if not provided.

### `Flags`

Acx element configuration flags defined by the [ACX_ELEMENT_CONFIG_FLAGS enum](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/ne-acxelements-acx_element_config_flags).

No flag bits are currently defined. Set this member to zero - AcxAudioElementConfigNoFlags

### `PropertiesCount`

The number of properties. This is a one based count.

### `MethodsCount`

The number of methods. This is a one based count.

### `Properties`

An [ACX_PROPERTY_ITEM structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_property_item) that defines the properties for this acx element configuration.

### `Methods`

An [ACX_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_method_item) structure that defines the methods for this acx element configuration.

## Remarks

### Example

Example usage is shown below.

```cpp
    WDF_OBJECT_ATTRIBUTES           attributes;
    ACX_ELEMENT_CONFIG              elementCfg;
    CODEC_ELEMENT_CONTEXT *         elementCtx;

    ACX_ELEMENT_CONFIG_INIT(&elementCfg);
    WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&attributes, CODEC_ELEMENT_CONTEXT);
    attributes.ParentObject = Circuit;

    status = AcxElementCreate(Circuit, &attributes, &elementCfg, Element);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxelements.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxelements/)