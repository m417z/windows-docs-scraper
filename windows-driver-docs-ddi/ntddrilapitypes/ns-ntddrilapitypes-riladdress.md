# RILADDRESS structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a phone number.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILADDRESSPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riladdressparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwType`

The type of address. Possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| RIL_ADDRTYPE_UNKNOWN | Unknown type |
| RIL_ADDRTYPE_INTERNATIONAL | International number |
| RIL_ADDRTYPE_NATIONAL | National/regional number |
| RIL_ADDRTYPE_NETWKSPECIFIC | Network-specific number |
| RIL_ADDRTYPE_SUBSCRIBER | Subscriber number (protocol-specific) |
| RIL_ADDRTYPE_ALPHANUM | Alphanumeric address |
| RIL_ADDRTYPE_ABBREV | Abbreviated number |
| RIL_ADDRTYPE_IP | IP address |
| RIL_ADDRTYPE_EMAIL | Internet email address (RFC 822) |

### `dwNumPlan`

The numbering scheme of the address. Possible values are shown in the following table.

| Value | Meaning |
| --- | --- |
| RIL_NUMPLAN_UNKNOWN | Unknown numbering plan |
| RIL_NUMPLAN_TELEPHONE | ISDN/telephone numbering plan (E.164/E.163) |
| RIL_NUMPLAN_DATA | Data numbering plan (X.121) |
| RIL_NUMPLAN_TELEX | Telex numbering plan |
| RIL_NUMPLAN_NATIONAL | National/regional numbering plan |
| RIL_NUMPLAN_PRIVATE | Private numbering plan |
| RIL_NUMPLAN_ERMES | ERMES numbering plan (ETSI DE/PS 3 01-3) |

### `wszAddress`

An array of address characters. The minimum length of this array is 3. When **dwType** is set to **RIL_ADDRTYPE_INTERNATIONAL**, the plus sign (+) is not prefixed to **wszAddress**. It is up to the client or modem to attach the symbol.

## Syntax

```cpp
struct RILADDRESS {
  DWORD cbSize;
  DWORD dwParams;
  DWORD dwType;
  DWORD dwNumPlan;
  WCHAR wszAddress[MAXLENGTH_ADDRESS];
};
```

## Remarks

When a **RILADDRESS** represents a phone number on a UICC card, the contents of **wszAddress** are constrained to values that can be represented on the card (as defined by 3GPP TS 31.102 table 4.4). In the UICC file, a phone number is represented by a string of 4-bit nibbles padded on the right with 0xF. The defined mapping is shown in the following table.

| nibble in UICC EF | WCHAR in wszAddress | Meaning |
| --- | --- | --- |
| 0x0 | L'0' | Digit 0 |
| 0x1 | L'1' | Digit 1 |
| 0x2 | L'2' | Digit 2 |
| 0x3 | L'3' | Digit 3 |
| 0x4 | L'4' | Digit 4 |
| 0x5 | L'5' | Digit 5 |
| 0x6 | L'6' | Digit 6 |
| 0x7 | L'7' | Digit 7 |
| 0x8 | L'8' | Digit 8 |
| 0x9 | L'9' | Digit 9 |
| 0xA | L'*' | Asterisk character |
| 0xB | L'#' | Pound character |
| 0xC | L'p' or L'P' | DTMF control digits separator (see 3GPP TS 22.101) |
| 0xD | L'?' | "Wild" value (see 3GPP TS 22.101) |
| 0xE |  | RFU—not to be used |
| 0xF |  | Padding for unused nibbles on UICC card—not to be used |

In the case of the control digits separator, either uppercase or lowercase 'P' may be passed in; the output is always lowercase. The RFU value 0xE should never appear on the card, but if it does it is reported as L'e'. It is an error to pass L'e' as input.

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))