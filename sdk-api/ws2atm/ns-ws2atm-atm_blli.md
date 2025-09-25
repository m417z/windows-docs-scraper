# ATM_BLLI structure

## Description

The
**ATM_BLLI** structure is used to identify B-LLI information for an associated ATM socket.

## Members

### `Layer2Protocol`

Identifies the layer-two protocol. Corresponds to the *User information layer 2 protocol* field in the B-LLI information element. A value of SAP_FIELD_ABSENT indicates that this field is not used, and a value of SAP_FIELD_ANY means wildcard.

### `Layer2UserSpecifiedProtocol`

Identifies the user-specified layer-two protocol. Only used if the **Layer2Protocol** parameter is set to BLLI_L2_USER_SPECIFIED. The valid values range from zero–127. Corresponds to the *User specified layer 2 protocol information* field in the B-LLI information element.

### `Layer3Protocol`

Identifies the layer-three protocol. Corresponds to the *User information layer 3 protocol* field in the B-LLI information element. A value of SAP_FIELD_ABSENT indicates that this field is not used, and a value of SAP_FIELD_ANY means wildcard.

### `Layer3UserSpecifiedProtocol`

Identifies the user-specified layer-three protocol. Only used if the **Layer3Protocol** parameter is set to BLLI_L3_USER_SPECIFIED. The valid values range from zero–127. Corresponds to the *User specified layer 3 protocol information* field in the B-LLI information element.

### `Layer3IPI`

Identifies the layer-three Initial Protocol Identifier. Only used if the **Layer3Protocol** parameter is set to BLLI_L3_ISO_TR9577. Corresponds to the *ISO/IEC TR 9577 Initial Protocol Identifier* field in the B-LLI information element.

### `SnapID`

Identifies the 802.1 SNAP identifier. Only used if the **Layer3Protocol** parameter is set to BLLI_L3_ISO_TR9577 and **Layer3IPI** is set to BLLI_L3_IPI_SNAP, indicating an IEEE 802.1 SNAP identifier. Corresponds to the *OUI* and *PID* fields in the B-LLI information element.

## Remarks

The following are the manifest constants associated with the
**ATM_BLLI** structure:

```cpp
#include <windows.h>

/*
 *  values used for Layer2Protocol in struct B-LLI
 */
#define BLLI_L2_ISO_1745           0x01   /* Basic mode ISO 1745    */
#define BLLI_L2_Q921               0x02   /* CCITT Rec. Q.921       */
#define BLLI_L2_X25L               0x06   /* CCITT Rec. X.25, link layer              */
#define BLLI_L2_X25M               0x07   /* CCITT Rec. X.25, multilink               */
#define BLLI_L2_ELAPB              0x08   /* Extended LAPB; for half duplex operation */
#define BLLI_L2_HDLC_NRM           0x09   /* HDLC NRM (ISO 4335)                      */
#define BLLI_L2_HDLC_ABM           0x0A   /* HDLC ABM (ISO 4335)                      */
#define BLLI_L2_HDLC_ARM           0x0B   /* HDLC ARM (ISO 4335)                      */
#define BLLI_L2_LLC                0x0C   /* LAN logical link control (ISO 8802/2)    */
#define BLLI_L2_X75                0x0D   /* CCITT Rec. X.75, single link procedure   */
#define BLLI_L2_Q922               0x0E   /* CCITT Rec. Q.922                         */
#define BLLI_L2_USER_SPECIFIED     0x10   /* User Specified                           */
#define BLLI_L2_ISO_7776           0x11   /* ISO 7776 DTE-DTE operation               */

/*
 *  values used for Layer3Protocol in struct B-LLI
 */
#define BLLI_L3_X25                0x06   /* CCITT Rec. X.25, packet layer            */
#define BLLI_L3_ISO_8208           0x07   /* ISO/IEC 8208 (X.25 packet layer for DTE  */
#define BLLI_L3_X223               0x08   /* X.223/ISO 8878                           */
#define BLLI_L3_SIO_8473           0x09   /* ISO/IEC 8473 (OSI connectionless)        */
#define BLLI_L3_T70                0x0A   /* CCITT Rec. T.70 min. network layer       */
#define BLLI_L3_ISO_TR9577         0x0B   /* ISO/IEC TR 9577 Network Layer Protocol ID*/
#define BLLI_L3_USER_SPECIFIED     0x10   /* User Specified                           */

/*
 *  values used for Layer3IPI in struct B-LLI
 */
#define BLLI_L3_IPI_SNAP           0x80   /* IEEE 802.1 SNAP identifier               */
#define BLLI_L3_IPI_IP             0xCC   /* Internet Protocol (IP) identifier        */

```

## See also

[ATM_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_address)

[ATM_BHLI](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_bhli)

[sockaddr_atm](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-sockaddr_atm)