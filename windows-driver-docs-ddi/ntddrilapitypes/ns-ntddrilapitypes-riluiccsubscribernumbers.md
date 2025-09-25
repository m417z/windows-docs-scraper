# RILUICCSUBSCRIBERNUMBERS structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents RILUICCSUBSCRIBERNUMBERS.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwNumSubscribers`

The number of subscribers.

### `rsiInfo`

Array of [RILSUBSCRIBERINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/rilapitypes/ns-rilapitypes-rilsubscriberinfo), each of which specifies a phone number assigned to the user as defined below. Although statically declared as a one-element array, the actual length is dwNumSubscribers.

## Syntax

```cpp
struct RILUMTSMRL {
  DWORD             cbSize;
  DWORD             dwNumSubscribers;
  RILSUBSCRIBERINFO rsiInfo[1];
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))