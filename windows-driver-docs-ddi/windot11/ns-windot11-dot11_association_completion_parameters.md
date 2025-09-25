# DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure

## Description

> [!IMPORTANT]
> [WiFiCx](https://learn.microsoft.com/windows-hardware/drivers/netcx/wifi-wdf-class-extension-wificx) is the new Wi-Fi driver model released in Windows 11. We recommend that you use WiFiCx to take advantage of the latest features. The WDI driver model is now in maintenance mode and will only receive high priority fixes.

The DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure specifies the results of the association operation performed by the 802.11 station with either an access point (AP) or peer station. The Native 802.11 miniport driver includes a DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure when the miniport driver makes an [NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) status indication.

## Members

### `Header`

The type, revision, and size of the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of *Header* to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_ASSOCIATION_COMPLETION_PARAMETERS_REVISION_1.

#### Size

This member must be set to `sizeof(DOT11_ASSOCIATION_COMPLETION_PARAMETERS)`.

For more information about these members, see [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `MacAddr`

The media access control (MAC) address of the access point (AP) (for infrastructure BSS networks) or peer station (for independent BSS (IBSS) networks) that the 802.11 station attempted to connect to.

### `uStatus`

The completion status of the association operation, as specified by a value defined for [DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes).

### `bReAssocReq`

A Boolean value that indicates whether the 802.11 station sent an 802.11 Association or Reassociation frame to the AP. If **TRUE**, the 802.11 station sent an 801.11 Reassociation Request frame to the AP. If **FALSE**, the 802.11 station sent an 802.11 Association Request frame to the AP.

A value of **TRUE** for the **bReAssocReq** member is valid only if the **dot11DesiredBSSType** MIB object is set to **dot11_BSS_type_infrastructure**.

### `bReAssocResp`

A Boolean value that indicates whether the 802.11 station received an 802.11 Association or Reassociation frame from the AP. If **TRUE**, the 802.11 station received an 802.11 Reassociation Response frame from the AP. If **FALSE**, the 802.11 station received an 802.11 Association Response frame from the AP.

A value of **TRUE** for the **bReAssocResp** member is valid only if the **dot11DesiredBSSType** MIB object is set to **dot11_BSS_type_infrastructure**.

### `uAssocReqOffset`

The offset of the request frame that is used in the association operation. The frame does not include the 802.11 MAC header.

This offset is relative to the start of the buffer that contains the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure.

The Association Request frame that is returned by the miniport driver depends on the setting of the IEEE 802.11 **dot11DesiredBSSType** MIB object:

- If the **dot11DesiredBSSType** MIB object is set to dot11_BSS_type_infrastructure, the frame is either the 802.11 Association Request frame (if **bReAssocReq** is **FALSE**) or Reassociation Request frame (if **bReAssocReq** is **TRUE**) that was sent to the AP.The miniport driver must return an 802.11 Probe Request frame that is either sent by the association initiator or created by the driver based on information that was exchanged during the association operation.
- If the **dot11DesiredBSSType** MIB object is set to dot11_BSS_type_independent, the miniport driver must set the **uAssocReqOffset** member to zero.

The miniport driver must set the **uAssocReqOffset** and **uAssocReqSize** members to zero if it was unable to send a request frame during the association operation. For example, if the AP failed the 802.11 Authentication frame that was sent by the 802.11 station, the miniport driver must set **uAssocReqOffset** and **uAssocReqSize** to zero.

### `uAssocReqSize`

The length of the request frame that is used in the association operation. The length of the frame does not include the 802.11 MAC header.

If the **dot11DesiredBSSType** MIB object is set to **dot11_BSS_type_independent**, the miniport driver must set the **uAssocReqSize** member to zero.

### `uAssocRespOffset`

The offset of the response frame that is used in the association operation. The frame does not include the 802.11 MAC header.

This offset is relative to the start of the buffer, which contains the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure.

The association response frame that is returned by the miniport driver depends on the setting of the IEEE 802.11 **dot11DesiredBSSType** MIB object:

- If the **dot11DesiredBSSType** MIB object is set to dot11_BSS_type_infrastructure, the frame is either the 802.11 Association Response frame (if **bReAssocReq** is **TRUE**) or Reassociation Response frame (if **bReAssocReq** is **FALSE**) that was received from the AP. The miniport driver must return an 802.11 Probe Response frame that is either sent to the association initiator or created by the driver based on information exchanged during the association operation.

- If the **dot11DesiredBSSType** MIB object is set to dot11_BSS_type_independent, the miniport driver must set the **uAssocRespOffset** member to zero.
- The miniport driver must set the **uAssocRespOffset** and **uAssocRespSize** members to zero if it did not receive a response frame during the association operation.

### `uAssocRespSize`

The length of the response frame that is used in the association operation. The length of the frame does not include the 802.11 MAC header.

If the **dot11DesiredBSSType** MIB object is set to **dot11_BSS_type_independent**, the miniport driver must set the **uAssocRespSize** member to zero.

### `uBeaconOffset`

The offset of the last received 802.11 Beacon or Probe Response frames. The miniport driver must exclude the 802.11 MAC header for these frames when making the [NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) status indication.

This offset is relative to the start of the buffer, which contains the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure.

> [!NOTE]
> If the authentication algorithm used on the association was Wi-Fi Protected Access (WPA) or IEEE 802.11i Robust Security Network Association (RSNA), the miniport driver must always return the last received 802.11 Beacon frame and must not set the **uBeaconOffset** and **uBeaconSize** members to zero.

### `uBeaconSize`

The length of the last received 802.11 Beacon frame. The length of the frame does not include the 802.11 MAC header.

### `uIHVDataOffset`

The offset of a block of data in a proprietary format that is defined by the IHV. The IHV can use this data block for any purposes that are related to the [NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) status indication.

This offset is relative to the start of the buffer, which contains the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure.

If the miniport driver is not returning IHV data in the [NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) status indication, it must set **uIHVDataOffset** to zero.

### `uIHVDataSize`

The length of the block of data that is used by the IHV for the [NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion) status indication. If the miniport driver is not returning IHV data in this indication, it must set **uIHVDataSize** to zero.

### `AuthAlgo`

The authentication algorithm that the 802.11 station resolved with the AP or peer station during the association operation. For more information about the data type for the **AuthAlgo** member, see [DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm).

The miniport driver must set this member to zero if **uStatus** is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.

### `UnicastCipher`

The unicast cipher algorithm that the 802.11 station resolved with the AP or peer station during the association operation. For more information about the data type for the **UnicastCipher** member, see [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

The miniport driver must set this member to zero if **uStatus** is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.

### `MulticastCipher`

The multicast cipher algorithm that the 802.11 station resolved with the AP or peer station during the association operation. For more information about the data type for the **MulticastCipher** member, see [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

The miniport driver must set this member to zero if **uStatus** is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.

### `uActivePhyListOffset`

The offset of the list of PHY identifiers (IDs) that the 802.11 station uses to send or receive packets on the BSS network connection.

The Extensible Station (ExtSTA) msDot11ActivePhyList MIB object also references the active PHY list.

For more information about this MIB object, see [OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list).

Entries in the active PHY list can be one of the following values:

- A PHY ID that is specified by the ExtSTA **msDot11DesiredPhyList** MIB object. For more information about this MIB object, see [OID_DOT11_DESIRED_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-phy-list).
- DOT11_PHY_ID_ANY. The miniport driver can set an entry to this value if the **msDot11ActivePhyList** MIB object specifies all of the PHY IDs that are specified by the **msDot11DesiredPhyList** MIB object. An entry with the value of DOT11_PHY_ID_ANY must be the only entry in the active PHY list.

The offset of the active PHY list is relative to the start of the buffer that contains the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure.

The miniport driver must set the **uActivePhyListOffset** and **uActivePhyListSize** members to zero if **uStatus** is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.

### `uActivePhyListSize`

The length of the active PHY list. The **uActivePhyListSize** member must be a multiple of `sizeof(ULONG)`.

### `bFourAddressSupported`

A Boolean value that, if set to **TRUE**, specifies that the 802.11 station has associated with an AP that supports distribution system (DS) services for ISO Layer 2 bridging on any station in the BSS network, including mobile stations and APs. The determination of this support is specific to the implementation by the IHV.

A miniport driver must set the **bFourAddressSupported** member to **FALSE** if any of the following are true:

- The IEEE 802.11 **dot11DesiredBSSType** MIB object is set to **dot11_BSS_type_independent**.
- The 802.11 station did not associate with an AP that supports DS services or cannot determine whether the AP supports DS services.
- The **uStatus** member is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.

### `bPortAuthorized`

A Boolean value that, if set to **TRUE**, specifies that the 802.11 station has successfully performed port authorization during the association operation. Port authorization could be based on either the IEEE 802.1X/802.11i standards or a proprietary algorithm that is developed by the IHV.

The miniport driver must set **bPortAuthorized** to **FALSE** if any of the following are true:

- The 802.11 station does not perform port authorization.
- The **uStatus** member is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.

For more information about port authorization, see [Port-Based Network Access](https://learn.microsoft.com/windows-hardware/drivers/network/port-based-network-access).

### `ucActiveQoSProtocol`

A flag that specifies the quality of service (QoS) protocol that is currently active for this association. This member is either zero (indicating that no QoS protocol is active) or one of the following flags:

#### DOT11_QOS_PROTOCOL_FLAG_WMM

The NIC is using the 802.11 WMM QoS protocol.

#### DOT11_QOS_PROTOCOL_FLAG_11E

The NIC is using the 802.11e QoS protocol.

### `DSInfo`

A DOT11_DS_INFO value that specifies whether the 802.11 station is connected to the same DS from the previous association operation.

The **DSInfo** member is formatted as a DOT11_DS_INFO enumeration, which specifies the following values:

#### DOT11_DS_CHANGED

The 802.11 station has connected to a new DS after the association operation.

#### DOT11_DS_UNCHANGED

The 802.11 station is connected to the same DS from the association operation.

#### DOT11_DS_UNKNOWN

The miniport driver cannot determine whether the DS has changed after the association operation.

> [!NOTE]
> The miniport driver must set **DSInfo** to **DOT11_DS_UNKNOWN** if the **dot11DesiredBSSType** MIB object is set to **dot11_BSS_type_independent**.

### `uEncapTableOffset`

The offset of the list of IEEE EtherType encapsulations for the BSS association.

This offset is relative to the start of the buffer, which contains the DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure. The value of **uEncapTableOffset** must be aligned on a 4-byte boundary.

The miniport driver formats each entry in this list as a [DOT11_ENCAP_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_encap_entry) structure.

For more information about the EtherType encapsulation list, see [802.11 Payload Encapsulation](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2003/cc757419(v=ws.10)).

### `uEncapTableSize`

The length of the EtherType encapsulation list.

### `MulticastMgmtCipher`

The multicast cipher algorithm the NIC chooses (negotiates) for the association for management frame protection (MFP). If MFP is negotiated, this member should be DOT11_CIPHER_ALGO_BIP. If MFP is not negotiated, this field should be DOT11_CIPHER_ALGO_NONE.

### `uAssocComebackTime`

When a (re)association fails with 802.11 reason code 30 ("Association request rejected temporarily, try again later.") this member indicates the value of the association comeback time requested by the access point (AP). The 802.11 disassociation reason code is present in the lowest 16 bits of **uStatus** when responding to an association request.

Windows' auto-connection service will add the AP to a blocked list and not attempt to reconnect for at least the indicated comeback time. The NIC will behave like a regular failed authentication until the next connection sequence is begun. After the indicated timeout(comeback) elapses and the connection process is stopped Windows may either find a better alternate connection or comeback to this connection. This value set in this member should use the time units defined in the 802.11 specification. For example, TU.

## Syntax

```cpp
typedef struct DOT11_ASSOCIATION_COMPLETION_PARAMETERS {
  NDIS_OBJECT_HEADER     Header;
  DOT11_MAC_ADDRESS      MacAddr;
  DOT11_ASSOC_STATUS     uStatus;
  BOOLEAN                bReAssocReq;
  BOOLEAN                bReAssocResp;
  ULONG                  uAssocReqOffset;
  ULONG                  uAssocReqSize;
  ULONG                  uAssocRespOffset;
  ULONG                  uAssocRespSize;
  ULONG                  uBeaconOffset;
  ULONG                  uBeaconSize;
  ULONG                  uIHVDataOffset;
  ULONG                  uIHVDataSize;
  DOT11_AUTH_ALGORITHM   AuthAlgo;
  DOT11_CIPHER_ALGORITHM UnicastCipher;
  DOT11_CIPHER_ALGORITHM MulticastCipher;
  ULONG                  uActivePhyListOffset;
  ULONG                  uActivePhyListSize;
  BOOLEAN                bFourAddressSupported;
  BOOLEAN                bPortAuthorized;
  UCHAR                  ucActiveQoSProtocol;
  DOT11_DS_INFO          DSInfo;
  ULONG                  uEncapTableOffset;
  ULONG                  uEncapTableSize;
  DOT11_CIPHER_ALGORITHM MulticastMgmtCipher;
  ULONG                  uAssocComebackTime;
} DOT11_ASSOCIATION_COMPLETION_PARAMETERS, *PDOT11_ASSOCIATION_COMPLETION_PARAMETERS;
```

## Remarks

The miniport driver must set the **uEncapTableOffset** and **uEncapTableSize** members to zero if any of the following are true:

- The BSS association does not require changes to the operating system's default list of EtherType encapsulations.
- The **uStatus** member is not set to DOT11_ASSOCIATION_STATUS_SUCCESS.
- The Extensible Station (ExtSTA) **dot11DesiredBSSType** management information base (MIB) object is set to **dot11_BSS_type_independent**.

For more information about the IEEE 802.11 **dot11DesiredBSSType** MIB object, see [OID_DOT11_DESIRED_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bss-type).

For more information about the association operation, see [Association Operations](https://learn.microsoft.com/windows-hardware/drivers/network/association-operations).

Management Frame Protection is negotiated when an access point (AP) and STA set the Management Frame Protection Capable (MFPC) field to 1 in their respective RSN IEs during the (re)association procedure (i.e. Beacon or Probe Response for AP and (re)association request for STA), and both parties confirm the Management Frame Protection Capable bit set to 1 in the 4-Way Handshake (Messages M2 and M3 of the 802.11i 4-way handshake).

## See also

[DOT11_ENCAP_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_encap_entry)

[DOT11_ASSOC_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/dot11-assoc-status-status-codes)

[NdisMIndicateStatusEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismindicatestatusex)

[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm)

[OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[DOT11_MAC_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-_dot11_mac_address)

[OID_DOT11_DESIRED_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-phy-list)

[OID_DOT11_DESIRED_BSS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-bss-type)

[NDIS_STATUS_DOT11_ASSOCIATION_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-dot11-association-completion)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)