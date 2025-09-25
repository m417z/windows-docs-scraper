# RILUICCFILELOCKSTATUS structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILUICCFILELOCKSTATUS.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILUICCFILELOCKSTATUSPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluiccfilelockstatusparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `dwAccessCondition`

Specifies the access condition for the file. These values correspond to those specified in ETSI TS 102 221 section 9.5.1. The access condition should be one of [RILUICCFILELOCKSTATUSACCESSCONDITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluiccfilelockstatusaccesscondition).

### `bPinRef`

A byte array specifying the application PIN references made by this application (keys for PIN1 and PIN2).

## Syntax

```cpp
struct RILUICCFILELOCKSTATUS {
  DWORD                                cbSize;
  DWORD                                dwParams;
  RILUICCFILELOCKSTATUSACCESSCONDITION dwAccessCondition;
  BYTE                                 bPinRef[MAXNUM_PINREF];
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))