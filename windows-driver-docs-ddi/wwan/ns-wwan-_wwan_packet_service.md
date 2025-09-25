# _WWAN_PACKET_SERVICE structure

## Description

The WWAN_PACKET_SERVICE structure represents the packet service attachment state of the MB
device.

## Members

### `uNwError`

A network specific error, in the event of a packet-attach or packet-detach failure. For more
information about this member, see the following
"Remarks" section.

### `PacketServiceState`

The packet service state of the device.

### `AvailableDataClass`

A bitmap that represents which data-classes are available to the device in the current network.
For a detailed list of values, see the
**WwanDataClass** member of
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps).

Miniport drivers must set this member to WWAN_DATA_CLASS_NONE when the device is not registered to a
network, or when there is no data-class, or when the supported data-class is not available. Miniport
drivers must set this member with a valid value when the device is registered to a network.

### `CurrentDataClass`

A single value from the
**WwanDataClass** member in
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps) that represents which
data-class is currently being used by the device.

For all data services, except HSPA, miniport drivers should set this member to a single
WWAN_DATA_CLASS_XXX value. For HSPA data services, miniport drivers should specify a bit-wise OR of
WWAN_DATA_CLASS_HSDPA and WWAN_DATA_CLASS_HSUPA.

Miniport drivers must set this member with a valid value and send the appropriate notification when
the device changes services, for example, from 1xRTT to 1xEV-DO.

Miniport drivers should set this member to WWAN_DATA_CLASS_CUSTOM if the data-class is not one of the
predefined values in the
**WwanDataClass** member of
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps).

### `FrequencyRange`

A [**WWAN_5G_FREQUENCY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_5g_frequency_range) value that specifies the frequency ranges that the device is using. This member is only valid if **CurrentDataClass** is either **WWAN_DATA_CLASS_5G_NSA** or **WWAN_DATA_CLASS_SA**.

### `CurrentDataSubClass`

This field is only used for NDIS_WWAN_PACKET_SERVICE_STATE_REVISION_3.

### `CurrentTai`

 A [**WWAN_SINGLE_TAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_tai) structure representing the current single Tracking Area Identity (TAI). This field is only used for NDIS_WWAN_PACKET_SERVICE_STATE_REVISION_3.

### `Rel3GppVer`

0xFFFFFFFF will be used if unknown. Unknown means either MBIM_TLV_TYPE_3GPP_REL_VERSION is not contained in MBIM_PACKET_SERVICE_INFO_V3, the device directly returns 0xFFFFFFFF,
or the device is using MBIM 3.0 or older.

## Remarks

The current packet-attach service state is typically reflected in the device's user interface.

The MB Service combines the data-classes that are represented in
**AvailableDataClass** with the supported data-classes that are reported with the device's capabilities
to display the intersection of the available choices to the user.

If a device also supports a data-class that is anything other than the predefined values in the
**WwanDataClass** member of
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps), the miniport driver
should set the WWAN_DATA_CLASS_CUSTOM flag along with the appropriate bitmask defined for the data-class
in this member.

*Query* and
*set* OID requests as well as unsolicited status events use the
**uNwError** member. If there is no network specific error or the network specific error is not known,
miniport drivers should set this member to zero. The
"Status Indication Structure" section in
[MB Operational Semantics](https://learn.microsoft.com/windows-hardware/drivers/network/mb-operational-semantics) shows the
packet-attach or packet-detach cause code failure values that are defined in the
*3GPP TS 24.008 Specification*.

The following points provide guidelines on returning network specific error in different
scenarios:

* If the packet-attach operation fails because of network specific error, miniport drivers should
  return the network specific error in response to
  *query* requests. In this case, miniport drivers should set the
  **uStatus** member of the NDIS_WWAN_PACKET_SERVICE_STATE structure to WWAN_STATUS_SUCCESS and set the
  **uNwError** member to the network specific error code.
* If a
  *set* request fails, miniport drivers should return the network specific error code. In this case,
  miniport drivers should set the
  **uStatus** member of the NDIS_WWAN_PACKET_SERVICE_STATE structure to WWAN_STATUS_FAILURE and set the
  **uNwError** member to the network specific error code.
* Whenever the device registration state changes because the network packet-detaches the device then
  unsolicited status events should include the network specific error. In this case, the miniport driver
  should set the
  **uStatus** member of the NDIS_WWAN_PACKET_SERVICE_STATE structure to WWAN_STATUS_SUCCESS and set the
  **uNwError** member to the network specific error code.

Miniport drivers can provide additional error codes as defined by the GSM standards specification of
packet-attach error codes returned by the network. For example, miniport drivers can communicate the 3GPP
specification TS 24.008 packet-attach error codes, such as error code 12 (Location area not allowed), to
the MB Service through the
**uNwError** member.

Miniport drivers must report the cause code at the earliest possible instance. For example, if the MB
device encounters one of these codes when attempting to register the device on with a network provider,
the miniport driver should report it at that time.

## See also

[NDIS_WWAN_PACKET_SERVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_packet_service_state)

[WWAN_PACKET_SERVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_packet_service_state)