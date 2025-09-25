# KSPROPERTY_SELECTOR_NODE_S structure

## Description

The KSPROPERTY_SELECTOR_NODE_S structure describes node-based property settings in the [PROPSETID_VIDCAP_SELECTOR](https://learn.microsoft.com/windows-hardware/drivers/stream/propsetid-vidcap-selector) property set.

## Members

### `NodeProperty`

Specifies an initialized [KSP_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_node) structure that describes the node, property set, property ID, and request type.

### `Value`

Specifies the value of a request. For Set requests, the minidriver should set the property specified in **Property** to this value. For Get requests, the minidriver should return the value of the property specified in **Property**.

### `Flags`

Specifies the flags of a request. For Set requests, this value indicates the desired setting. For Get requests, this value contains the current setting.

### `Capabilities`

Specifies the capabilities of a property. This member has meaning only for Get requests. The minidriver should return the capabilities of the Selector with respect to the property specified in **Property**.

## See also

[KSPROPERTY_SELECTOR_S](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksproperty_selector_s)