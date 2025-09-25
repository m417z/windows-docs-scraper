# PrivateData structure

## Description

**Note** The Network Access Protection platform is not available starting with Windows 10

The **PrivateData** structure is used to store and retrieve opaque data blobs.

## Members

### `size`

The size, in bytes, of **data** in the range 0 to [maxPrivateDataSize](https://learn.microsoft.com/windows/desktop/NAP/nap-type-constants).

### `data`

A pointer to the opaque data blob.

## Remarks

The **PrivateData** structure is used to store state information for the NapAgent and enforcement clients. It is queried and set by the [INapSystemHealthValidationRequest](https://learn.microsoft.com/windows/desktop/NAP/inapsystemhealthvalidationrequest) and [INapEnforcementClientConnection](https://learn.microsoft.com/windows/desktop/NAP/inapenforcementclientconnection) interfaces.

## See also

[NAP Reference](https://learn.microsoft.com/windows/desktop/NAP/nap-reference)

[NAP Structures](https://learn.microsoft.com/windows/desktop/NAP/nap-structures)