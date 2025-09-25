# CorrelationId structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **CorrelationId** structure is used to pair [SoHRequests](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) with **SoHResponses** and uniquely describes an SoH exchange.

## Members

### `connId`

A globally unique identifier (GUID) that identifies a SoH exchange.

### `timeStamp`

A unique [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) value that contains the system time at which the [SoHRequest](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) was generated.

## Remarks

The
string version, [StringCorrelationId](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes), is used primarily for logging purposes,
whereas this byte version is used by SHA/SHVs to
match [SoHRequests](https://learn.microsoft.com/windows/desktop/api/naptypes/ns-naptypes-soh) to **SoHResponses**.

## See also

[NAP Datatypes](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes)

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)