# _PCPROPERTY_REQUEST structure

## Description

The **PCPROPERTY_REQUEST** structure specifies a property request.

## Members

### `MajorTarget`

[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointer to the main miniport object. This member contains the *UnknownMiniport* parameter value that the adapter driver previously passed to the [IPort::Init](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iport-init) method.

### `MinorTarget`

[IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointer to a stream object that is associated with the **MajorTarget** miniport object. If the target for the property request is a pin instance, this member contains the stream-object pointer that the IMiniport *Xxx*::NewStream method previously output to the port driver (for example, the [IMiniportWaveCyclic::NewStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iminiportwavecyclic-newstream) method's *Stream* parameter). Otherwise (if the target for the property request is a filter instance), this member is **NULL**.

### `Node`

Specifies a node ID. This member identifies the target node for the request. If the target is not a node, this member is set to ULONG(-1).

### `PropertyItem`

Pointer to the property item, which is a structure of type [PCPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcproperty_item).

### `Verb`

Specifies the type of property request. **Verb** is set to the bitwise OR of one or more of the following flag bits from header file ks.h:

* KSPROPERTY_TYPE_GET
* KSPROPERTY_TYPE_SET
* KSPROPERTY_TYPE_SETSUPPORT
* KSPROPERTY_TYPE_BASICSUPPORT
* KSPROPERTY_TYPE_RELATIONS
* KSPROPERTY_TYPE_SERIALIZESET
* KSPROPERTY_TYPE_UNSERIALIZESET
* KSPROPERTY_TYPE_SERIALIZERAW
* KSPROPERTY_TYPE_UNSERIALIZERAW
* KSPROPERTY_TYPE_SERIALIZESIZE
* KSPROPERTY_TYPE_DEFAULTVALUES
* KSPROPERTY_TYPE_TOPOLOGY

These flags are described in [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `InstanceSize`

Specifies the size in bytes of the property-instance buffer.

### `Instance`

Pointer to the property-instance buffer

### `ValueSize`

Specifies the size in bytes of the property-value buffer.

### `Value`

Pointer to the property-value buffer

### `Irp`

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) containing the client's original property request

## Remarks

This is the structure that the port driver passes to the miniport driver's property-handler routine. The [PCPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcproperty_item) structure contains a function pointer to a property handler that takes a **PCPROPERTY_REQUEST** pointer as its only call parameter. The port driver allocates a **PCPROPERTY_REQUEST** structure, extracts the relevant information from the original property request (which the **Irp** member points to), and loads the information into this structure before calling the handler.

In WDM audio, the target of a property request can be either a filter instance or a pin instance. The target can also include a node ID.

In the client's original property request, the property-instance data always begins with a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) or [KSNODEPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty) structure, but can include additional information. The port driver adjusts the **PCPROPERTY_REQUEST** structure's **Instance** member to point to this additional information, if it exists. For details, see [Audio Property Handlers](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-property-handlers).

The **MajorTarget** and **MinorTarget** members are [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointers to the main miniport object and an associated stream object, respectively. The property handler can query these objects for their miniport and stream interfaces. If the target for the property request is a filter instance, **MajorTarget** points to the miniport object for that filter instance, and **MinorTarget** is **NULL**. If the target is a pin instance, **MinorTarget** points to the stream object for that pin, and **MajorTarget** points to the miniport object for the filter that the pin is attached to.

For example, if the target for the property request is a pin instance on a WaveCyclic filter:

* The handler can call [QueryInterface](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the **MajorTarget** object's [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface to obtain a reference to the object's [IMiniportWaveCyclic](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavecyclic) interface.
* The handler can call [QueryInterface](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the **MinorTarget** object's [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface to obtain a reference to the object's [IMiniportWaveCyclicStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavecyclicstream) interface.

For background information about audio properties, see [Audio Endpoints, Properties and Events](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-endpoints--properties-and-events). For a list of the available audio-specific properties, see [Audio Drivers Property Sets](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-drivers-property-sets).

## See also

[KSNODEPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty)

[KSNODEPROPERTY_AUDIO_CHANNEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksnodeproperty_audio_channel)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[PCPROPERTY_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcproperty_item)