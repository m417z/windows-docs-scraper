# RILSUBSCRIBERINFO structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILSUBSCRIBERINFO.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwParams`

A bitwise combination of [RILSUBSCRIBERINFOPARAMMASK](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilsubscriberinfoparammask) enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `raAddress`

Phone number of the subscriber line, of type [RILADDRESSTYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-riladdresstype).

### `wszDescription`

Text description of the subscriber line.

### `dwService`

Specifies the service related to the subscriber phone number, of type [RILSUBSCRIBERINFOSERVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ne-rilapitypes-rilsubscriberinfoservice).

## Syntax

```cpp
struct RILSUBSCRIBERINFO {
  DWORD                    cbSize;
  DWORD                    dwParams;
  RILADDRESS               raAddress;
  WCHAR                    wszDescription[MAXLENGTH_DESCRIPTION];
  RILSUBSCRIBERINFOSERVICE dwService;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))