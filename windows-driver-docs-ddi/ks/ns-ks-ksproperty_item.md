## Description

Drivers use the KSPROPERTY_ITEM structure to describe how they support a property in a property set.

## Members

### `PropertyId`

Specifies the ID of the property being described.

### `GetPropertyHandler`

Pointer to a minidriver-supplied [KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85)). If **NULL**, the property cannot be read. This member is used only by drivers that use the AVStream or Stream class interfaces.

### `GetSupported`

Set to **TRUE** if this property supports get requests, **FALSE** if it does not. (The class driver fulfills the request through the SRB_GET_DEVICE_PROPERTY or SRB_GET_STREAM_PROPERTY requests.) This member is used only by minidrivers running under stream class.

### `MinProperty`

Specifies the minimum buffer length to hold the property identifier. This must be at least **sizeof**([**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)).

### `MinData`

Specifies the minimum buffer length to hold the data read from or written to this property.

### `SetPropertyHandler`

Pointer to a minidriver-supplied [KStrSetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567200(v=vs.85)). If **NULL**, the property cannot be set. This member is used only by drivers that use the AVStream or Stream class interfaces.

### `SetSupported`

Set to **TRUE** if this property supports set requests, **FALSE** if it does not. (The class driver fulfills the request through the SRB_SET_DEVICE_PROPERTY or SRB_SET_STREAM_PROPERTY requests.)

### `Values`

Pointer to a structure of type [**KSPROPERTY_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values). Specifies the acceptable and/or default values for the property. These are the same as the values reported by a driver in response to an IOCTL_KS_PROPERTY request with the KSPROPERTY_TYPE_BASICSUPPORT and KSPROPERTY_TYPE_DEFAULTVALUES flags set.

### `RelationsCount`

Specifies the number of entries in the array pointed to by the **Relations** member.

### `Relations`

Points to an array of [**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structures representing properties related to this one. Two properties are considered related if changing one property may affect the value of the other property. The **Flags** member of each entry is unused.

### `SupportHandler`

Provide this member only if implementing your own format for raw serialization or raw unserialization. Basic support queries, range queries, and relations queries are automatically handled by AVStream, which returns the relevant values from other members of this KSPROPERTY_ITEM structure.

### `SerializedSize`

Specifies the size of the property when serialized in a KSPROPERTY_TYPE_SERIALIZESET request. This should be zero if the property cannot be serialized. See [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) for more information.

## Remarks

Stream class minidrivers use KSPROPERTY_ITEM to describe to the client how to fulfill property requests on each property within a set. Handling for the property set as a whole is specified in the [KSPROPERTY_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set) structure, which contains pointers to arrays of KSPROPERTY_ITEM structures.

The stream class driver handles property requests on behalf of the minidriver. When the stream class driver requires more information from the minidriver, it passes an SRB_XXX request to one of the minidriver's **StrMiniReceiveXXXRequest** routines. The stream class driver handles the different request types as listed in the following table.

| Property request flags value | Response |
|---|---|
| KSPROPERTY_TYPE_GET | If **GetSupported** is **TRUE**, the stream class driver submits an [**SRB_GET_DEVICE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-device-property) or [**SRB_GET_STREAM_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-property) request to the appropriate minidriver **StrMiniReceiveXXXRequest** routine. |
| KSPROPERTY_TYPE_SET | If **SetSupported** is **TRUE**, the stream class driver submits an [**SRB_SET_DEVICE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-device-property) or [**SRB_SET_STREAM_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-stream-property) request to the appropriate minidriver **StrMiniReceiveXXXRequest** routine. |
| KSPROPERTY_TYPE_BASICSUPPORT | The stream class driver uses KSPROPERTY_ITEM to obtain the information necessary to fulfill this request. For example, to specify the data type and permitted ranges of the property data, they each use the **Values** member of this structure. |
| KSPROPERTY_TYPE_SETSUPPORT | The stream class driver completes the property request IRP as STATUS_SUCCESS only if the driver supplies an entry for the property set within its [**KSPROPERTY_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set) structure. |
| KSPROPERTY_TYPE_DEFAULTVALUES | The stream class driver uses the **Values** member of this structure to determine the default values for the property data. |
| KSPROPERTY_TYPE_RELATIONS | The stream class driver uses the **Relations** member to determine what properties are related to this property. |

If the client specifies KSPROPERTY_TYPE_DEFAULTVALUES, the driver uses the data buffer to return a description of its value type, including possibly its allowed range and default value. This flag is similar in result to KSPROPERTY_TYPE_BASICSUPPORT, except that any values returned are those that have been marked with KSPROPERTY_MEMBER_FLAG_DEFAULT in the **Flags** member of the structure [**KSPROPERTY_MEMBERSHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_membersheader).

For more information, see [KS Properties](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-properties).

## See also

[**KSPROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[**KSPROPERTY_SET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_set)

[**KSPROPERTY_VALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksproperty_values)

[**SRB_GET_DEVICE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-device-property)

[**SRB_GET_STREAM_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-property)

[**SRB_SET_DEVICE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-device-property)

[**SRB_SET_STREAM_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-stream-property)