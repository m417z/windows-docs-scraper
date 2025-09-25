# ATM_BHLI structure

## Description

The
**ATM_BHLI** structure is used to identify B-HLI information for an associated ATM socket.

## Members

### `HighLayerInfoType`

Identifies the **high layer information type** field in the B-LLI information element. Note that the type **BHLI_HighLayerProfile** has been eliminated in UNI 3.1. A value of SAP_FIELD_ABSENT indicates that B-HLI is not present, and a value of SAP_FIELD_ANY means wildcard.

### `HighLayerInfoLength`

Identifies the number of bytes from one to eight in the **HighLayerInfo** array. Valid values include eight for the cases of BHLI_ISO and BHLI_UserSpecific, four for BHLI_HighLayerProfile, and seven for BHLI_VendorSpecificAppId.

### `HighLayerInfo`

Identifies the **high layer information** field in the B-LLI information element. In the case of **HighLayerInfoType** being BHLI_VendorSpecificAppId, the first 3 bytes consist of a globally-administered organizationally unique identifier (OUI), (according to IEEE standard 802-1990), followed by a 4-byte application identifier, which is administered by the vendor identified by the OUI. Value for the case of BHLI_UserSpecific is user defined and requires bilateral agreement between two end users.

## Remarks

The following are the manifest constants associated with the
**ATM_BHLI** structure:

```cpp
#include <windows.h>
/*
 *  values used for the HighLayerInfoType field in struct ATM_BHLI
 */

#define BHLI_ISO                   0x00   /* ISO                                 */
#define BHLI_UserSpecific          0x01   /* User Specific                       */
#define BHLI_HighLayerProfile      0x02   /* High layer profile (only in UNI3.0) */
#define BHLI_VendorSpecificAppId   0x03   /* Vendor-Specific Application ID      */

```

## See also

[ATM_ADDRESS](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_address)

[ATM_BLLI](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-atm_blli)

[sockaddr_atm](https://learn.microsoft.com/windows/desktop/api/ws2atm/ns-ws2atm-sockaddr_atm)