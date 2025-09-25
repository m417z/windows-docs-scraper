# _DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS structure

## Description

**Important** The [Native 802.11 Wireless LAN](https://learn.microsoft.com/previous-versions/windows/hardware/wireless/ff560689(v=vs.85)) interface is deprecated in Windows 10 and later. Please use the WLAN Device Driver Interface (WDI) instead. For more information about WDI, see [WLAN Universal Windows driver model](https://learn.microsoft.com/windows-hardware/drivers/network/wifi-universal-driver-model).

The DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS structure specifies the results of the association operation that is performed by the 802.11 station after it receives an association request from a peer station on an infrastructure BSS.

## Members

### `Header`

The type, revision, and size of the DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS structure. This member is formatted as an [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure.

The miniport driver must set the members of **Header** to the following values:

#### Type

This member must be set to NDIS_OBJECT_TYPE_DEFAULT.

#### Revision

This member must be set to DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS_REVISION_1.

#### Size

This member must be set to **sizeof**(DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS).

For more information about these members, see [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `PeerMacAddr`

The media access control (MAC) address of the peer station that sent an association request.

### `uStatus`

The status of the association with the peer station. If zero, the association succeeds. If nonzero, the association fails.

### `ucErrorSource`

For nonzero values of **uStatus**, this member indicates the source of the error that prevents association. The NIC must set **ucErrorSource** to one of the following values:

#### DOT11_ASSOC_ERROR_SOURCE_OS

The miniport driver has rejected the association procedure because of system errors, such as out-of-memory errors. In this case, **uStatus** should be set to the NDIS_STATUS_XXX or NTSTATUS_XXX code returned from the operating system.

#### DOT11_ASSOC_ERROR_SOURCE_REMOTE

The AP or the peer station has rejected the association procedure. In this case, **uStatus** should be set to the 802.11 status code form the 802.11 authentication frame, association response frame, or re-association response frame. Table 19 in the *IEEE 802.11-2003 Specification* contains all the possible values. The miniport driver can also return new values in this IEEE specification when it is amended.

#### DOT11_ASSOC_ERROR_SOURCE_OTHER

The association failed for an IHV-specific reason. In this case, **uStatus** contains a nonzero value specified by the IHV.

### `bReAssocReq`

A Boolean value that indicates whether the request from the peer station is a re-association request.

### `bReAssocResp`

A Boolean value that indicates whether the response from the NIC is a re-association request.

### `uAssocReqOffset`

The offset of the request frame that is used in the association operation. The frame includes information elements (IEs) but does not include the 802.11 MAC header.

### `uAssocReqSize`

The length, in bytes, of the request frame that is used in the association operation. The frame includes information elements (IEs) but does not include the 802.11 MAC header.

### `uAssocRespOffset`

The offset of the response frame that is used in the association operation. The frame includes information elements (IEs) but does not include the 802.11 MAC header.

### `uAssocRespSize`

The length of the response frame, in bytes, that is used in the association operation. The frame includes information elements (IEs) but does not include the 802.11 MAC header.

### `AuthAlgo`

The authentication algorithm that the 802.11 station resolved with the peer station during the association operation. For more information about the data type for the **AuthAlgo** member, see [DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm).

**Note** The miniport driver must set this member to zero if **uStatus** is not set to zero.

### `UnicastCipher`

The unicast cipher algorithm that the 802.11 station resolved with the peer station during the association operation. For more information about the data type for the
**UnicastCipher** member, see [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

**Note** The miniport driver must set this member to zero if **uStatus** is not set to zero.

### `MulticastCipher`

The multicast cipher algorithm that the 802.11 station resolved with the AP or peer station during the association operation. For more information about the data type for the **MulticastCipher** member, see [DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm).

**Note** The miniport driver must set this member to zero if **uStatus** is not set to zero.

### `uActivePhyListOffset`

The offset of the list of PHY identifiers (IDs) that the 802.11 station uses to send or receive packets on the BSS network connection. Each entry is a ULONG value.

The Extensible Station (ExtSTA) [msDot11ActivePhyList](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list) MIB object also references the active PHY list.

Entries in the active PHY list can be one of the following values:

* A PHY ID that is specified by the Extensible Station (ExtSTA)
  **msDot11DesiredPhyList** management information base (MIB) object. For more information about this
  MIB object, see
  [OID_DOT11_DESIRED_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-desired-phy-list).
* A PHY ID of DOT11_PHY_ID_ANY. The miniport driver can set an entry to this value if the ExtSTA
  **msDot11ActivePhyList** MIB object specifies all of the PHY IDs that are specified by the
  **msDot11DesiredPhyList** MIB object. For more information about this MIB object, see
  [OID_DOT11_ACTIVE_PHY_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-dot11-active-phy-list).

  **Note** An entry with the value of DOT11_PHY_ID_ANY must be the only entry in the
  active PHY list.

The offset of the active PHY list is relative to the start of the buffer that contains the
DOT11_ASSOCIATION_COMPLETION_PARAMETERS structure.

**Note** The miniport driver must set this member to zero if
**uStatus** is not set to zero.

### `uActivePhyListSize`

The length, in bytes, of the active PHY list. The
**uActivePhyListSize** member must be a multiple of
`sizeof(ULONG)`.

**Note** The miniport driver must set this member to zero if
**uStatus** is not set to zero.

### `uBeaconOffset`

The offset, in bytes, of the last transmitted 802.11 Beacon frame.

The Beacon frame includes the Beacon frame header and all information elements (IEs), but it does not
include the 802.11 MAC header. The Beacon frame format is defined in ISO/IEC 8802-11.

The Beacon frame should be the latest frame used by the driver, except that real-time parameters or
IEs that vary with data frame flow control, or client association status such as timestamp, radio
parameters, TIM, ERP, and HT IEs, do not need to be accurate,

**Note** The miniport driver must set this member to zero if
**uStatus** is not set to zero.

### `uBeaconSize`

The length, in bytes, of the last transmitted 802.11 Beacon frame.

The Beacon frame includes the Beacon frame header and all information elements (IEs), but it does not
include the 802.11 MAC header. The Beacon frame format is defined in ISO/IEC 8802-11.

The Beacon frame should be the latest frame used by the driver, except that real-time parameters or
IEs that vary with data frame flow control, or client association status such as timestamp, radio
parameters, TIM, ERP, and HT IEs, do not need to be accurate,

**Note** The miniport driver must set this member to zero if
**uStatus** is not set to zero.

## Syntax

```cpp
typedef struct _DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS {
  NDIS_OBJECT_HEADER     Header;
  DOT11_MAC_ADDRESS      PeerMacAddr;
  ULONG                  uStatus;
  UCHAR                  ucErrorSource;
  BOOLEAN                bReAssocReq;
  BOOLEAN                bReAssocResp;
  ULONG                  uAssocReqOffset;
  ULONG                  uAssocReqSize;
  ULONG                  uAssocRespOffset;
  ULONG                  uAssocRespSize;
  DOT11_AUTH_ALGORITHM   AuthAlgo;
  DOT11_CIPHER_ALGORITHM UnicastCipher;
  DOT11_CIPHER_ALGORITHM MulticastCipher;
  ULONG                  uActivePhyListOffset;
  ULONG                  uActivePhyListSize;
  ULONG                  uBeaconOffset;
  ULONG                  uBeaconSize;
} DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS, *PDOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS;
```

## Remarks

The Native 802.11 miniport driver includes a DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS structure when
the driver makes an
[NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters) status indication.

The NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION status indication marks the end of an
*association indication block*. If the association is successful, the NIC must make the
NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION indication after it successfully sends the corresponding
association response frame to the station that originally requested the association. If the association
fails, the NIC must make the NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION indication whether the response
is sent successfully or not. The failure can be because the NIC or operating system reject the
association request or because of a failure not related to the 802.11 framework.

## See also

[DOT11_AUTH_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_auth_algorithm)

[NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION](https://learn.microsoft.com/windows-hardware/drivers/ddi/windot11/ns-windot11-dot11_association_completion_parameters)

[DOT11_CIPHER_ALGORITHM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wlantypes/ne-wlantypes-_dot11_cipher_algorithm)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)