# RILUICCLOCK structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILUICCLOCK.

## Members

### `hUiccApp`

Specifies the UICC application context for this lock. In the case of PIN1 or UPIN, more than one application may make reference to the same key.

### `dwKeyRef`

The key for this lock of [RILUICCKEYREF](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riluicckeyref) type. PIN1 keys are in the range 0x01..0x08 and may be shared by multiple applications. The Universal PIN is designated with key 0x11. PIN2 keys are in the range 0x81..0x88 and are local to each application (not shared). Two additional special values are defined: 0x00 represents a lock that is always verified (the “ALWays” access condition on the UICC) and 0xFF represents a lock that cannot be verified (the “NEVer” access condition).

## Syntax

```cpp
struct RILUICCLOCK {
  HUICCAPP hUiccApp;
  DWORD    dwKeyRef;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))