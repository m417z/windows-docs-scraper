# IBitsPeer::GetPeerName

## Description

Gets the server principal name that uniquely identifies the peer.

## Parameters

### `pName` [out]

Null-terminated string that contains the server principal name of the peer. The principal name is of the form, server$.domain.suffix. Call the
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free *pName* when done.

## Return value

The method returns the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success |

## Remarks

The principal name ensures the unique identity of the peer computer and is the entity that Kerberos authenticates.

## See also

[IBitsPeer](https://learn.microsoft.com/windows/desktop/api/bits3_0/nn-bits3_0-ibitspeer)