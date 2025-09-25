# _WINBIO_REGISTERED_FORMAT structure

## Description

The WINBIO_REGISTERED_FORMAT structure specifies a biometric data format.

## Members

### `Owner`

Specifies format owner.

### `Type`

Specifies format type.

## Remarks

For Windows, the format owner is defined as follows:

```cpp
#define WINBIO_ANSI_381_FORMAT_OWNER    ((USHORT)0x001B)    // INCITS Technical Committee M1
```

The Type for the standard Windows fingerprint format is:

```cpp
#define WINBIO_ANSI_381_FORMAT_TYPE     ((USHORT)0x0401)    // ANSI-381
```

WBDI drivers for fingerprint sensors must support the Owner and Type for the Windows fingerprint data format. The Windows Biometric Service (WBS) verifies that a sensor minimally supports the Windows fingerprint raw data format. Windows defines this standard raw data format to allow ISVs to write engine adapters that can take input from any sensor. Each engine should have a capability to support at least this format, but it can specify a different format as a preferred raw format.

For information about formats for other types of sensors, see [Client Application Constants](https://learn.microsoft.com/windows/win32/secbiomet/client-application-constants).

No format owner or type are defined as follows:

```cpp
#define WINBIO_NO_FORMAT_OWNER_AVAILABLE    ((USHORT)0)
#define WINBIO_NO_FORMAT_TYPE_AVAILABLE     ((USHORT)0)
```