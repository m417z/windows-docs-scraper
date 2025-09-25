## Description

The **KSPROPERTY_VIDEOPROCAMP_NODE_S** structure describes node-based property settings in the [PROPSETID_VIDCAP_VIDEOPROCAMP](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-videoprocamp) property set.

## Members

### `NodeProperty`

Specifies an initialized [**KSP_NODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node) structure that describes the node, property set, property ID, and request type.

### `Value`

Specifies the value of a request. For Set requests, the minidriver should set the property specified in **Property** to this value. For Get requests, the minidriver should return the value of the property specified in **Property**.

### `Flags`

Specifies the flags of a request. For Set requests, this value indicates the desired setting. For Get requests, this value contains the current setting. This member can be set to one of the values that are defined in *ksmedia.h*:

| Flag | Meaning |
|---|---|
| KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL | Indicates that the property is to be adjusted manually. |
| KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO | Indicates that the property is to be adjusted automatically. |

### `Capabilities`

Specifies the capabilities of a property. This member has meaning only for Get requests. The minidriver should return the capabilities of the VideoProcAmp with respect to the property specified in **Property**. This member should be set to one of the following values:

| Value | Meaning |
|---|---|
| KSPROPERTY_VIDEOPROCAMP_FLAGS_MANUAL | The device supports manual setting of the specified property. |
| KSPROPERTY_VIDEOPROCAMP_FLAGS_AUTO | The device supports automatic setting of the specified property. |

## See also

[**KSPROPERTY_VIDEOPROCAMP_S**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_videoprocamp_s)